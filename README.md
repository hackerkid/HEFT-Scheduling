# HEFT-Scheduling Algorithm 
C++ implemntation of Performance-effective and low-complexity task scheduling for heterogeneous computing

##About
Efficient application scheduling is critical for achieving high performance in heterogeneous computing environments. The 
application scheduling problem has been shown to be NP-complete in general cases as well as in several restricted cases.
Because of its key importance, this problem has been extensively studied and various algorithms have been proposed in the 
literature which are mainly for systems with homogeneous processors. Although there are a few algorithms in the literature 
for heterogeneous processors, they usually require significantly high scheduling costs and they may not deliver good quality
schedules with lower costs. In this paper, we present two novel scheduling algorithms for a bounded number of heterogeneous 
processors with an objective to simultaneously meet high performance and fast scheduling time, which are called the
Heterogeneous Earliest-Finish-Time (HEFT) algorithm and the Critical-Path-on-a-Processor (CPOP) algorithm. The HEFT algorithm 
selects the task with the highest upward rank value at each step and assigns the selected task to the processor, which
minimizes its earliest finish time with an insertion-based approach. On the other hand, the CPOP algorithm uses the summation 
of upward and downward rank values for prioritizing tasks. Another difference is in the processor selection phase, which 
schedules the critical tasks onto the processor that minimizes the total execution time of the critical tasks. In order to 
provide a robust and unbiased comparison with the related work, a parametric graph generator was designed to generate weighted
directed acyclic graphs with various characteristics. The comparison study, based on both randomly generated graphs and the 
graphs of some real applications, shows that our scheduling algorithms significantly surpass previous approaches in terms of
both quality and cost of schedules, which are mainly presented with schedule length ratio, speedup, frequency of best results,
and average scheduling time metrics.

##Research Paper

[Link](http://ieeexplore.ieee.org/xpl/articleDetails.jsp?arnumber=993206&tag=1)

###Authors

Author(s)

* Topcuoglu, H - Comput. Eng. Dept., Marmara Univ., Istanbul, Turkey 
* Hariri, S. - Min-You Wu


