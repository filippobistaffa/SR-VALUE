PK: a Scalable Algorithm to Compute Kernel-Stable Payments for Social Ridesharing
===================
PK is an algorithm to compute [Kernel](https://en.wikipedia.org/wiki/Cooperative_game_theory#The_kernel)-stable payments for [Social Ridesharing](http://www.aaai.org/ocs/index.php/AAAI/AAAI15/paper/download/9622/9303). PK has been presented by Filippo Bistaffa, Georgios Chalkiadakis, Alessandro Farinelli, and Sarvapali D. Ramchurn in “[Recommending Fair Payments for Large-Scale Social Ridesharing](http://dx.doi.org/10.1145/2792838.2800177)”, Proceedings of the 2015 ACM Conference on Recommender Systems (RecSys), pages 139–146, 2015, ACM.

Requirements
----------
PK requires `g++` to compile, and does not require any external library to execute.

Execution
----------
PK must be executed by means of the [`pk.sh`](https://github.com/filippobistaffa/PK/blob/master/pk.sh) script, i.e.,
```
./pk.sh INPUTFILE
```
where `INPUTFILE` is the solution file generated by [SR-CFSS](https://github.com/filippobistaffa/SR-CFSS) using the `-pk` command-line option.

Acknowledgements
----------
SR-CFSS employs the [GeoLife dataset by Microsoft Research](http://research.microsoft.com/en-us/projects/geolife) presented by Yu Zheng, Quannan Li, Yukun Chen, Xing Xie, and Wei-Ying Ma in “[Understanding mobility based on GPS data](https://www.microsoft.com/en-us/research/publication/understanding-mobility-based-on-gps-data)”, Proceedings of the 10th ACM conference on Ubiquitous Computing (Ubicomp), pages 312−321, 2008, ACM press.
