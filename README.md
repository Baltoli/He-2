# He-2

Updated, portable version of [Helium][helium].

## Helium

The original version of Helium appeared in the [paper][paper]:

> Mendis, C. et al. (2015) ‘Helium: Lifting High-performance Stencil Kernels from
> Stripped x86 Binaries to Halide DSL Code’, in Proceedings of the 36th ACM
> SIGPLAN Conference on Programming Language Design and Implementation. New York,
> NY, USA: ACM (PLDI ’15), pp. 391–402. doi: [10.1145/2737924.2737974][paper].

## Limitations

* This version of the project does not yet support interposing Halide-generated
  functions using DynamoRIO (i.e. only the analysis and detection phase is
  implemented).

[helium]: https://github.com/CharithYMendis/Helium
[paper]: https://dl.acm.org/doi/10.1145/2737924.2737974
