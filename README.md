SR-VALUE: compute the SR value of a coalition structure
===================

SR-VALUE computes the value of a coalition structure in the SR scenario. 

Execution
----------
SR-VALUE must be executed by means of the [`srvalue.sh`](srvalue.sh) script, i.e.,
```
./srvalue.sh -i <filename> -s <seed> [-c]

-i	Input filename
-s	Seed
-c	Enable CSV output
```

Input File Format
----------
The input file must be structured according to the following format.

  * `N` (i.e., the number of agents) in the first line.
  * `K` (i.e., the maximum coalition cardinality) in the second line.
  * `M` lines representing the `M` coalitions in the solution coalition structure. Each line must contain the coalition's members. Drivers must be marked by preceding their indices with `*` (e.g., `*0` means that `0` is a driver). At the moment, SR-VALUE supports only coalitions with one driver.

The following example file represents a solution of the instance with `N` = 10, seed = 47, and `K` = 5.
The solution coalition structure is `{{9},{6},{2},{7,0,1,3,8},{4},{5}}`, where `7` is a driver. 

```
10
5
9
6
2
*7 0 1 3 8
4
5
```

Acknowledgements
----------
SR-VALUE employs the [GeoLife dataset by Microsoft Research](http://research.microsoft.com/en-us/projects/geolife) presented by Yu Zheng, Quannan Li, Yukun Chen, Xing Xie, and Wei-Ying Ma in “[Understanding mobility based on GPS data](https://www.microsoft.com/en-us/research/publication/understanding-mobility-based-on-gps-data)”, Proceedings of the 10th ACM conference on Ubiquitous Computing (Ubicomp), pages 312−321, 2008, ACM press.
