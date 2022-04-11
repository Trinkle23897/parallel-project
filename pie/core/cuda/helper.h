#ifndef PIE_CORE_CUDA_HELPER_H_
#define PIE_CORE_CUDA_HELPER_H_

#include <tuple>

#include "solver.h"
#include "util.h"

class CudaEquSolver : public EquSolver {
 protected:
  int* maskbuf;
  unsigned char* imgbuf;
  int block_size;
  // CUDA
  int* cA;
  unsigned char* cimgbuf;
  float *cB, *cX, *cerr, *tmp;

 public:
  explicit CudaEquSolver(int block_size);
  ~CudaEquSolver();

  py::array_t<int> partition(py::array_t<int> mask);
  void post_reset();
  std::tuple<py::array_t<unsigned char>, py::array_t<float>> step(
      int iteration);
};

class CudaGridSolver : public GridSolver {
 protected:
  unsigned char* imgbuf;
  // CUDA
  int* cmask;
  unsigned char* cimgbuf;
  float *ctgt, *cgrad, *cerr, *tmp;

 public:
  explicit CudaGridSolver(int grid_x, int grid_y);
  ~CudaGridSolver();

  void post_reset();
  std::tuple<py::array_t<unsigned char>, py::array_t<float>> step(
      int iteration);
};

#endif  // PIE_CORE_CUDA_HELPER_H_