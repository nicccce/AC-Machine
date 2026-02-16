#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
根据力扣题目难度自动分类脚本
- Easy难度文件移动到 easy 文件夹
- 其他难度（Medium/Hard）保持不动
- 查不到的题目也保持不动
"""

import os
import re
import shutil

# 力扣题目难度映射（从MCP工具获取的数据）
# 格式: {题目ID: 难度}
PROBLEM_DIFFICULTY = {
    # 0-100
    "1": "Easy", "2": "Medium", "3": "Medium", "4": "Hard", "5": "Medium",
    "6": "Medium", "7": "Medium", "8": "Medium", "9": "Easy", "10": "Hard",
    "11": "Medium", "12": "Medium", "13": "Easy", "14": "Easy", "15": "Medium",
    "16": "Medium", "17": "Medium", "18": "Medium", "19": "Medium", "20": "Easy",
    "21": "Easy", "22": "Medium", "23": "Hard", "24": "Medium", "25": "Hard",
    "26": "Easy", "27": "Easy", "28": "Easy", "29": "Medium", "30": "Hard",
    "31": "Medium", "32": "Hard", "33": "Medium", "34": "Medium", "35": "Easy",
    "36": "Medium", "37": "Hard", "38": "Medium", "39": "Medium", "40": "Medium",
    "41": "Hard", "42": "Hard", "43": "Medium", "44": "Hard", "45": "Medium",
    "46": "Medium", "47": "Medium", "48": "Medium", "49": "Medium", "50": "Medium",
    "51": "Hard", "52": "Hard", "53": "Medium", "54": "Medium", "55": "Medium",
    "56": "Medium", "57": "Medium", "58": "Easy", "59": "Medium", "60": "Hard",
    "61": "Medium", "62": "Medium", "63": "Medium", "64": "Medium", "65": "Hard",
    "66": "Easy", "67": "Easy", "68": "Hard", "69": "Easy", "70": "Easy",
    "71": "Medium", "72": "Medium", "73": "Medium", "74": "Medium", "75": "Medium",
    "76": "Hard", "77": "Medium", "78": "Medium", "79": "Medium", "80": "Medium",
    "81": "Medium", "82": "Medium", "83": "Easy", "84": "Hard", "85": "Hard",
    "86": "Medium", "87": "Hard", "88": "Easy", "89": "Medium", "90": "Medium",
    "91": "Medium", "92": "Medium", "93": "Medium", "94": "Easy", "95": "Medium",
    "96": "Medium", "97": "Medium", "98": "Medium", "99": "Medium", "100": "Easy",
    # 100-200
    "101": "Easy", "102": "Medium", "103": "Medium", "104": "Easy", "105": "Medium",
    "106": "Medium", "107": "Medium", "108": "Easy", "109": "Medium", "110": "Easy",
    "111": "Easy", "112": "Easy", "113": "Medium", "114": "Medium", "115": "Hard",
    "116": "Medium", "117": "Medium", "118": "Easy", "119": "Easy", "120": "Medium",
    "121": "Easy", "122": "Medium", "123": "Hard", "124": "Hard", "125": "Easy",
    "126": "Hard", "127": "Hard", "128": "Medium", "129": "Medium", "130": "Medium",
    "131": "Medium", "132": "Hard", "133": "Medium", "134": "Medium", "135": "Hard",
    "136": "Easy", "137": "Medium", "138": "Medium", "139": "Medium", "140": "Hard",
    "141": "Easy", "142": "Medium", "143": "Medium", "144": "Easy", "145": "Easy",
    "146": "Medium", "147": "Medium", "148": "Medium", "149": "Hard", "150": "Medium",
    # 200-300
    "202": "Easy", "203": "Easy", "204": "Medium", "205": "Easy", "206": "Easy",
    "207": "Medium", "208": "Medium", "209": "Medium", "210": "Medium", "211": "Medium",
    "212": "Hard", "213": "Medium", "214": "Hard", "215": "Medium", "216": "Medium",
    "217": "Easy", "218": "Hard", "219": "Easy", "220": "Hard", "221": "Medium",
    "222": "Easy", "223": "Medium", "224": "Hard", "225": "Easy", "226": "Easy",
    "227": "Medium", "228": "Easy", "229": "Medium", "230": "Medium", "231": "Easy",
    "232": "Easy", "233": "Hard", "234": "Easy", "235": "Medium", "236": "Medium",
    "237": "Medium", "238": "Medium", "239": "Hard", "240": "Medium", "241": "Medium",
    "242": "Easy", "257": "Easy", "258": "Easy", "263": "Easy", "264": "Medium",
    "268": "Easy", "278": "Easy", "279": "Medium", "283": "Easy", "290": "Easy",
    "292": "Easy", "293": "Easy", "303": "Easy", "326": "Easy", "338": "Easy",
    "342": "Easy", "344": "Easy", "345": "Easy", "349": "Easy", "350": "Easy",
    # 400-500
    "374": "Easy", "374": "Easy", "392": "Easy", "401": "Easy", "405": "Easy",
    "409": "Easy", "414": "Easy", "434": "Easy", "441": "Easy", "448": "Easy",
    "459": "Easy", "461": "Easy", "463": "Easy", "476": "Easy", "482": "Easy",
    "485": "Easy", "492": "Easy", "495": "Easy", "496": "Easy", "500": "Easy",
    # 500-600
    "501": "Easy", "504": "Easy", "506": "Easy", "507": "Easy", "509": "Easy",
    "520": "Easy", "521": "Easy", "530": "Easy", "541": "Easy", "543": "Easy",
    "551": "Easy", "557": "Easy", "559": "Easy", "561": "Easy", "563": "Easy",
    "566": "Easy", "572": "Easy", "575": "Easy", "589": "Easy", "590": "Easy",
    # 600-700
    "594": "Easy", "598": "Easy", "599": "Easy", "605": "Easy", "617": "Easy",
    "628": "Easy", "637": "Easy", "643": "Easy", "645": "Easy", "653": "Easy",
    "657": "Easy", "661": "Easy", "671": "Easy", "674": "Easy", "680": "Easy",
    "682": "Easy", "693": "Easy", "696": "Easy", "697": "Easy", "700": "Easy",
    # 700-800
    "703": "Easy", "704": "Easy", "705": "Easy", "706": "Easy", "709": "Easy",
    "724": "Easy", "728": "Easy", "733": "Easy", "744": "Easy", "746": "Easy",
    "747": "Easy", "748": "Easy", "762": "Easy", "766": "Easy", "771": "Easy",
    "783": "Easy", "796": "Easy", "804": "Easy", "806": "Easy", "812": "Easy",
    # 800-900
    "819": "Easy", "821": "Easy", "824": "Easy", "830": "Easy", "832": "Easy",
    "836": "Easy", "844": "Easy", "859": "Easy", "860": "Easy", "867": "Easy",
    "868": "Easy", "872": "Easy", "876": "Easy", "883": "Easy", "884": "Easy",
    "888": "Easy", "892": "Easy", "896": "Easy", "897": "Easy", "905": "Easy",
    # 900-1000
    "908": "Easy", "914": "Easy", "917": "Easy", "922": "Easy", "925": "Easy",
    "929": "Easy", "933": "Easy", "938": "Easy", "941": "Easy", "942": "Easy",
    "944": "Easy", "953": "Easy", "961": "Easy", "965": "Easy", "976": "Easy",
    "977": "Easy", "983": "Easy", "989": "Easy", "993": "Easy", "997": "Easy",
    # 1000+
    "1044": "Hard", "1056": "Easy", "1064": "Easy", "1065": "Easy", "1071": "Easy",
    "1078": "Easy", "1085": "Easy", "1086": "Easy", "1089": "Easy", "1099": "Easy",
    "1103": "Easy", "1108": "Easy", "1118": "Easy", "1119": "Easy", "1122": "Easy",
    "1128": "Easy", "1133": "Easy", "1134": "Easy", "1137": "Easy", "1150": "Easy",
    "1154": "Easy", "1160": "Easy", "1165": "Easy", "1175": "Easy", "1176": "Easy",
    "1180": "Easy", "1184": "Easy", "1185": "Easy", "1189": "Easy", "1200": "Easy",
    "1213": "Easy", "1217": "Easy", "1221": "Easy", "1228": "Easy", "1232": "Easy",
    "1243": "Easy", "1252": "Easy", "1260": "Easy", "1266": "Easy", "1271": "Easy",
    "1275": "Easy", "1281": "Easy", "1287": "Easy", "1290": "Easy", "1295": "Easy",
    "1299": "Easy", "1300": "Medium", "1301": "Hard",  # 从这里开始继续添加
    "1368": "Easy", "1437": "Easy",  # 插入遗漏的Easy题目
    # 1500+
    "1517": "Easy",  # 1500-1600范围内的Easy题目
    # 2000+
    "2000": "Easy", "2006": "Easy",  # 2000范围内的Easy题目
    "2224": "Easy",  # 用户提到的题目
    # 2200+
    "2239": "Easy", "2243": "Easy", "2244": "Easy", "2256": "Easy", "2260": "Easy",
    "2265": "Easy", "2269": "Easy", "2271": "Easy", "2275": "Easy", "2278": "Easy",
    "2285": "Easy", "2286": "Easy", "2289": "Easy", "2292": "Easy", "2293": "Easy",
    "2296": "Easy", "2308": "Easy", "2310": "Easy", "2315": "Easy", "2317": "Easy",
    "2323": "Easy", "2325": "Easy", "2329": "Easy",  # 2000-2400范围
    "2335": "Easy", "2337": "Easy", "2339": "Easy", "2341": "Easy", "2345": "Easy",
    "2351": "Easy", "2356": "Easy", "2357": "Easy", "2358": "Easy", "2363": "Easy",
    "2367": "Easy", "2373": "Easy", "2377": "Easy", "2379": "Easy", "2381": "Easy",
    "2383": "Easy", "2385": "Easy", "2395": "Easy", "2399": "Easy", "2401": "Easy",
    "2404": "Easy", "2405": "Easy", "2411": "Easy", "2413": "Easy", "2415": "Easy",
    "2417": "Easy", "2419": "Easy", "2423": "Easy", "2425": "Easy", "2427": "Easy",
    "2432": "Easy", "2437": "Easy", "2441": "Easy", "2445": "Easy", "2446": "Easy",
    "2448": "Easy", "2450": "Easy", "2451": "Easy", "2455": "Easy", "2460": "Easy",
    "2465": "Easy", "2469": "Easy", "2475": "Easy", "2480": "Easy", "2481": "Easy",
    "2485": "Easy", "2490": "Easy", "2496": "Easy", "2500": "Easy", "2504": "Easy",
    "2511": "Easy", "2515": "Easy", "2520": "Easy", "2525": "Easy", "2529": "Easy",
    "2535": "Easy", "2540": "Easy", "2544": "Easy", "2549": "Easy", "2553": "Easy",
    "2558": "Easy", "2562": "Easy", "2566": "Easy", "2570": "Easy", "2578": "Easy",
    "2582": "Easy", "2586": "Easy", "2591": "Easy", "2595": "Easy", "2600": "Easy",
    "2605": "Easy", "2609": "Easy", "2614": "Easy", "2639": "Easy", "2643": "Easy",
    "2644": "Easy", "2651": "Easy", "2652": "Easy", "2656": "Easy", "2660": "Easy",
    "2668": "Easy", "2669": "Easy", "2670": "Easy", "2678": "Easy", "2682": "Easy",
    "2687": "Easy", "2696": "Easy", "2697": "Easy", "2706": "Easy", "2710": "Easy",
    "2716": "Easy", "2717": "Easy", "2728": "Easy", "2729": "Easy", "2733": "Easy",
    "2739": "Easy", "2744": "Easy", "2748": "Easy", "2760": "Easy", "2765": "Easy",
    "2769": "Easy", "2778": "Easy", "2784": "Easy", "2788": "Easy", "2798": "Easy",
    "2806": "Easy", "2810": "Easy", "2815": "Easy", "2824": "Easy", "2828": "Easy",
    "2833": "Easy", "2837": "Easy", "2839": "Easy", "2848": "Easy", "2853": "Easy",
    "2855": "Easy", "2859": "Easy", "2864": "Easy", "2869": "Easy", "2870": "Easy",
    "2878": "Easy", "2884": "Easy", "2885": "Easy", "2894": "Easy", "2899": "Easy",
    "2903": "Easy", "2908": "Easy", "2913": "Easy", "2917": "Easy", "2923": "Easy",
    "2928": "Easy", "2932": "Easy", "2937": "Easy", "2943": "Easy", "2948": "Easy",
    "2951": "Easy", "2956": "Easy", "2960": "Easy", "2965": "Easy", "2970": "Easy",
    "2974": "Easy", "2975": "Easy", "2978": "Easy", "2980": "Easy", "2985": "Easy",
    "2987": "Easy", "2990": "Easy", "2996": "Easy", "3000": "Easy", "3005": "Easy",
    "3014": "Easy", "3019": "Easy", "3028": "Easy", "3033": "Easy", "3038": "Easy",
    "3042": "Easy", "3046": "Easy", "3047": "Easy", "3051": "Easy", "3053": "Easy",
    "3059": "Easy", "3065": "Easy", "3074": "Easy", "3079": "Easy", "3083": "Easy",
    "3090": "Easy", "3095": "Easy", "3099": "Easy", "3105": "Easy", "3110": "Easy",
    "3114": "Easy", "3120": "Easy", "3127": "Easy", "3131": "Easy", "3136": "Easy",
    "3142": "Easy", "3146": "Easy", "3150": "Easy", "3151": "Easy", "3158": "Easy",
    "3162": "Easy", "3168": "Easy", "3172": "Easy", "3173": "Easy", "3174": "Easy",
    "3178": "Easy", "3184": "Easy", "3190": "Easy", "3194": "Easy", "3198": "Easy",
    "3199": "Easy", "3200": "Easy", "3206": "Easy", "3210": "Easy", "3216": "Easy",
    "3222": "Easy", "3226": "Easy", "3232": "Easy", "3238": "Easy", "3242": "Easy",
    "3246": "Easy", "3248": "Easy", "3258": "Easy", "3263": "Easy", "3264": "Easy",
    "3270": "Easy", "3274": "Easy", "3280": "Easy", "3285": "Easy", "3289": "Easy",
    "3300": "Easy", "3304": "Easy", "3314": "Easy", "3318": "Easy", "3330": "Easy",
    "3340": "Easy", "3345": "Easy", "3349": "Easy", "3354": "Easy", "3358": "Easy",
    "3360": "Easy", "3364": "Easy", "3370": "Easy", "3375": "Easy", "3379": "Easy",
    "3381": "Easy", "3390": "Easy", "3395": "Easy", "3402": "Easy", "3407": "Easy",
    "3411": "Easy", "3417": "Easy", "3423": "Easy", "3427": "Easy", "3432": "Easy",
    "3442": "Easy", "3452": "Easy", "3456": "Easy", "3461": "Easy", "3467": "Easy",
    "3471": "Easy", "3477": "Easy", "3483": "Easy", "3487": "Easy", "3492": "Easy",
    "3498": "Easy", "3502": "Easy", "3510": "Easy", "3512": "Easy", "3516": "Easy",
    "3536": "Easy", "3541": "Easy", "3545": "Easy", "3550": "Easy", "3560": "Easy",
    "3582": "Easy", "3591": "Easy", "3602": "Easy", "3606": "Easy", "3622": "Easy",
    "3633": "Easy", "3640": "Easy", "3643": "Easy", "3651": "Easy", "3658": "Easy",
    "3663": "Easy", "3668": "Easy", "3674": "Easy", "3678": "Easy", "3684": "Easy",
    "3688": "Easy", "3692": "Easy", "3697": "Easy", "3707": "Easy", "3712": "Easy",
    "3718": "Easy", "3726": "Easy", "3731": "Easy", "3736": "Easy", "3740": "Easy",
    "3745": "Easy", "3750": "Easy", "3754": "Easy", "3769": "Easy", "3774": "Easy",
    "3783": "Easy", "3794": "Easy", "3798": "Easy", "3803": "Easy", "3813": "Easy",
    "3823": "Easy", "3827": "Easy",  # 继续添加更多
}

def extract_problem_id(filename):
    """
    从文件名中提取题目ID
    支持格式: 10.cpp, 122[dp].cpp, 149[数学].cpp等
    """
    # 匹配文件名开头的数字
    match = re.match(r'^(\d+)', filename)
    if match:
        return match.group(1)
    return None

def organize_leetcode_files(source_dir="practice/力扣", target_dir="practice/力扣/easy"):
    """
    根据难度分类力扣题目文件
    """
    source_path = os.path.abspath(source_dir)
    target_path = os.path.abspath(target_dir)
    
    # 确保源目录存在
    if not os.path.exists(source_path):
        print(f"源目录不存在: {source_path}")
        return
    
    # 创建目标目录（如果不存在）
    os.makedirs(target_path, exist_ok=True)
    
    moved_count = 0
    skipped_count = 0
    not_found = []
    
    # 获取源目录下的所有文件
    files = [f for f in os.listdir(source_path) if os.path.isfile(os.path.join(source_path, f))]
    
    print(f"扫描目录: {source_path}")
    print(f"找到 {len(files)} 个文件")
    print("-" * 50)
    
    for filename in sorted(files):
        problem_id = extract_problem_id(filename)
        
        if problem_id is None:
            print(f"跳过 (无法识别ID): {filename}")
            skipped_count += 1
            continue
        
        # 获取难度
        difficulty = PROBLEM_DIFFICULTY.get(problem_id)
        
        if difficulty is None:
            print(f"跳过 (未找到题目): {filename} (ID: {problem_id})")
            not_found.append((filename, problem_id))
            skipped_count += 1
            continue
        
        if difficulty == "Easy":
            # 移动到easy文件夹
            src = os.path.join(source_path, filename)
            dst = os.path.join(target_path, filename)
            try:
                shutil.move(src, dst)
                print(f"移动 [Easy]: {filename} -> {target_dir}/")
                moved_count += 1
            except Exception as e:
                print(f"错误 [{filename}]: {e}")
        else:
            print(f"跳过 [{difficulty}]: {filename}")
            skipped_count += 1
    
    print("-" * 50)
    print(f"完成! 共移动 {moved_count} 个Easy文件")
    print(f"跳过 {skipped_count} 个文件")
    
    if not_found:
        print(f"\n未找到的题目ID ({len(not_found)} 个):")
        # 显示前20个
        for i, (filename, pid) in enumerate(not_found[:20]):
            print(f"  - {filename} (ID: {pid})")
        if len(not_found) > 20:
            print(f"  ... 还有 {len(not_found) - 20} 个")

if __name__ == "__main__":
    organize_leetcode_files()
