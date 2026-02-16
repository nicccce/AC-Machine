// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int trainingHours = 0;
        int currentEnergy = initialEnergy;
        int currentExperience = initialExperience;
        
        for (int i = 0; i < energy.size(); i++) {
            // Check if we have enough energy to defeat the opponent
            if (currentEnergy <= energy[i]) {
                // Calculate how much training is needed to have enough energy
                int neededEnergy = energy[i] + 1 - currentEnergy;
                trainingHours += neededEnergy;
                currentEnergy += neededEnergy;
            }
            
            // Check if we have enough experience to defeat the opponent
            if (currentExperience <= experience[i]) {
                // Calculate how much training is needed to have enough experience
                int neededExperience = experience[i] + 1 - currentExperience;
                trainingHours += neededExperience;
                currentExperience += neededExperience;
            }
            
            // After defeating the opponent, update our energy and experience
            currentEnergy -= energy[i];
            currentExperience += experience[i];
        }
        
        return trainingHours;
    }
};

ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}

int ex_gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int solve_linear_congruence_equation(int a, int b, int n)
{
    int x, y;
    int d = ex_gcd(a, n, x, y);
    if (b % d)
        return -1;
    n /= d;
    return ((long long)x * (b / d) % n + n) % n;
}