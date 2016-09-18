PC: an Algorithm to Compute Core-Stable Payments for Social Ridesharing
===================
This branch contains the code to compute a core-stable allocation for Social Ridesharing. This code is not scalable (since computing payments in the core is untractable), and must be used only for experimental purposes.

Requirements
----------
PC requires `g++` to compile, and relies on [IBM CPLEX](https://www-01.ibm.com/software/commerce/optimization/cplex-optimizer) to compute a core-stable payment allocation. In order to compile againt CPLEX, `INC` and `LDIR` inside [`Makefile`](https://github.com/filippobistaffa/PK/blob/core/Makefile)  must be set to point to the `include` and `lib` folders of CPLEX.

Execution
----------
PC must be executed by means of the [`pc.sh`](https://github.com/filippobistaffa/PK/blob/core/pc.sh) script, i.e.,
```
./pc.sh INPUTFILE
```
where `INPUTFILE` is the solution file generated by [SR-CFSS](https://github.com/filippobistaffa/SR-CFSS) using the `-p` command-line option.

Input File Format
----------
`INPUTFILE` is the path of the input file, which must be structured according to the following format.

  * `N` (i.e., the number of agents) in the first line.
  * `K` (i.e., the maximum coalition cardinality) in the second line.
  * `SEED` (i.e., the seed used to generate the pseudo-random SR instance) in the third line.
  * `N` lines, each containing the list of the neighbours of the i<sup>th</sup> agent in the graph. Specifically, each line must be formatted in the following way.
	  * First number is the agent's degree *d* in the graph
	  * The following *d* numbers are the indices of the agent's neighbours in the graph
  * `M` lines representing the `M` coalitions in the solution coalition structure. Each line must contain the coalition's members. Drivers must be marked by preceding their indices with `*` (e.g., `*0` means that `0` is a driver).

The following example file represents a solution of the instance with `SEED` = 47, `K` = 5, and with the following graph.
<p align="center"><img src="http://i.imgur.com/cFGCpbz.png" width="500" /></p>
The solution coalition structure is `{{9},{6},{2},{7,0,1,3,8},{4},{5}}`, where `7` is a driver. 

```
10
5
47
6 7 1 2 3 4 8
6 0 2 3 4 5 6
4 0 1 6 9
3 0 1 8
5 7 0 1 5 9
2 1 4
2 1 2
2 0 4
2 0 3
2 2 4
9
6
2
*7 0 1 3 8
4
5
```

Acknowledgements
----------
PK employs the [GeoLife dataset by Microsoft Research](http://research.microsoft.com/en-us/projects/geolife) presented by Yu Zheng, Quannan Li, Yukun Chen, Xing Xie, and Wei-Ying Ma in “[Understanding mobility based on GPS data](https://www.microsoft.com/en-us/research/publication/understanding-mobility-based-on-gps-data)”, Proceedings of the 10th ACM conference on Ubiquitous Computing (Ubicomp), pages 312−321, 2008, ACM press.
