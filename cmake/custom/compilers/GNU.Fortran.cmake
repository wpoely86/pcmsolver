# Overrides contents of all variables previously set by CMake
if(NOT DEFINED ENV{FCFLAGS})
    if(CMAKE_Fortran_COMPILER_ID MATCHES GNU)
        set(CMAKE_Fortran_FLAGS "-DVAR_GFORTRAN -DGFORTRAN=445 -fimplicit-none -fPIC -fautomatic")
        set(CMAKE_Fortran_FLAGS_DEBUG   "-O0 -g -fbacktrace -Wall -Wextra ${Fcheck_all}")
        set(CMAKE_Fortran_FLAGS_RELEASE "-O3 -funroll-all-loops -ftree-vectorize")
    endif()
endif()