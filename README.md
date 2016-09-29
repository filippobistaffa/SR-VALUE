CSVALUE: compute the SR value of a coalition structure
===================

Execution
----------
PC must be executed by means of the [`csvalue.sh`](csvalue.sh) script, i.e.,
```
./csvalue.sh INPUTFILE
```

Input File Format
----------
`INPUTFILE` is the path of the input file, which must be structured according to the following format.

  * `N` (i.e., the number of agents) in the first line.
  * `K` (i.e., the maximum coalition cardinality) in the second line.
  * `SEED` (i.e., the seed used to generate the pseudo-random SR instance) in the third line.
  * `M` lines representing the `M` coalitions in the solution coalition structure. Each line must contain the coalition's members. Drivers must be marked by preceding their indices with `*` (e.g., `*0` means that `0` is a driver).

The following example file represents a solution of the instance with `N` = 10, `SEED` = 47, and `K` = 5.
The solution coalition structure is `{{9},{6},{2},{7,0,1,3,8},{4},{5}}`, where `7` is a driver. 

```
10
5
47
9
6
2
*7 0 1 3 8
4
5
```

Acknowledgements
----------
CSVALUE employs the [GeoLife dataset by Microsoft Research](http://research.microsoft.com/en-us/projects/geolife) presented by Yu Zheng, Quannan Li, Yukun Chen, Xing Xie, and Wei-Ying Ma in “[Understanding mobility based on GPS data](https://www.microsoft.com/en-us/research/publication/understanding-mobility-based-on-gps-data)”, Proceedings of the 10th ACM conference on Ubiquitous Computing (Ubicomp), pages 312−321, 2008, ACM press.
