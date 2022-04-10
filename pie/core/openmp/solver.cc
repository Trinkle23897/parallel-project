#include "helper.h"

PYBIND11_MODULE(pie_core_openmp, m) {
  py::class_<OpenMPEquSolver>(m, "EquSolver")
      .def(py::init<int>())
      .def("partition", &OpenMPEquSolver::partition)
      .def("reset", &OpenMPEquSolver::reset)
      .def("sync", &OpenMPEquSolver::sync)
      .def("step", &OpenMPEquSolver::step);
  py::class_<OpenMPGridSolver>(m, "GridSolver")
      .def(py::init<int>())
      .def("reset", &OpenMPGridSolver::reset)
      .def("sync", &OpenMPGridSolver::sync)
      .def("step", &OpenMPGridSolver::step);
}
