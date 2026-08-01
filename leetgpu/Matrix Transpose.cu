#include <cuda_runtime.h>

__global__ void matrix_transpose_kernel(const float* input, float* output, int rows, int cols) {
    __shared__ float tile[16][16 + 1]; // +1 to avoid bank conflicts
    dim3 idx(blockDim.x*blockIdx.x+threadIdx.x,blockDim.y*blockIdx.y+threadIdx.y);
    if (idx.x<cols&&idx.y<rows){
        tile[threadIdx.y][threadIdx.x]=input[idx.y*cols+idx.x];
    }
    __syncthreads();
    dim3 transposed_idx(blockDim.y*blockIdx.y+threadIdx.x,blockDim.x*blockIdx.x+threadIdx.y);
    if (transposed_idx.x<rows&&transposed_idx.y<cols){
        output[transposed_idx.y*rows+transposed_idx.x]=tile[threadIdx.x][threadIdx.y];
    }
    // if (idx.x<cols&&idx.y<rows){
    //     output[idx.x*rows+idx.y]=input[idx.y*cols+idx.x];
    // }
}

// input, output are device pointers (i.e. pointers to memory on the GPU)
extern "C" void solve(const float* input, float* output, int rows, int cols) {
    dim3 threadsPerBlock(16, 16);
    dim3 blocksPerGrid((cols + threadsPerBlock.x - 1) / threadsPerBlock.x,
                       (rows + threadsPerBlock.y - 1) / threadsPerBlock.y);

    matrix_transpose_kernel<<<blocksPerGrid, threadsPerBlock>>>(input, output, rows, cols);
    cudaDeviceSynchronize();
}
