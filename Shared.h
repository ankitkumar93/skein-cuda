#include <iostream>
#include <cstdint>
#include <cuda/cuda.h>

using namespace std;

// Globals
static constexpr uint64_t kHashSizeBits = 128;

// Assert
void AssertHandler(string condition, string file, int line)
{
    cerr << "Assertion failed: " << condition << " in file: " << file << " at line: " << line << endl;
}

#define ASSERT(cond) if (!cond) AssertHandler(#cond, __FILE__, __LINE__)

// Device memory management
/**
 * Allocate memory on the GPU
 * 
 * @param data the pointer to the memory
 * @param size the size of the memory block
 */
void DeviceMalloc(void* data, size_t size)
{
    cudaError_t err = cudaMalloc(&data, kHashSizeBits);
    if (err != cudaSuccess)
    {
        fprintf(stderr, "cuda malloc failed, err: %s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

/**
 * Deallocate memory on the GPU
 * 
 * @param data the pointer to the memory
 */
void DeviceFree(void* data)
{
    cudaError_t err = cudaFree(&data);
    if (err != cudaSuccess)
    {
        fprintf(stderr, "cuda free failed, err: %s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

/**
 * Copy data from host to GPU
 * 
 * @param hostDataPtr the pointer to the memory on host
 * @param deviceDataPtr the pointer to the memory on device
 * @param size the number of bytes to be copied
 */
void HostToDeviceCpy(void* hostDataPtr, void* deviceDataPtr, size_t size)
{
    cudaError_t err = cudaMemCpy(&deviceDataPtr, &hostData, size);
    if (err != cudaSuccess)
    {
        fprintf(stderr, "cuda host to device memcpy failed, err: %s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}

/**
 * Copy data from GPU to host
 * 
 * @param hostDataPtr the pointer to the memory on host
 * @param deviceDataPtr the pointer to the memory on device
 * @param size the number of bytes to be copied
 */
void DeviceToHostCpy(void* hostDataPtr, void* deviceDataPtr, size_t size)
{
    cudaError_t err = cudaMemCpy(&hostDataPtr, &deviceDataPtr, size);
    if (err != cudaSuccess)
    {
        fprintf(stderr, "cuda device to host memcpy failed, err: %s\n", cudaGetErrorString(err));
        exit(EXIT_FAILURE);
    }
}