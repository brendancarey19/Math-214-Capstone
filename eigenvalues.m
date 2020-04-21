%% script to find the eigenvalues of the adjacency matrix %%

%%%
A = [0 0 0 0 0 0 0 1 1 0;
     0 0 0 0 0 0 1 0 0 1;
     0 0 0 0 0 0 1 0 1 0;
     0 0 0 0 0 0 1 1 0 0;
     0 0 0 0 0 0 0 0 1 1;
     0 0 0 0 0 0 0 1 0 1;
     0 1 1 1 0 0 0 0 0 0;
     1 0 0 1 0 1 0 0 0 0;
     1 0 1 0 1 0 0 0 0 0;
     0 1 0 0 1 1 0 0 0 0];
 
 B =[0 0 0 0 0 0 0 0 1 0;
     0 0 0 0 0 0 0 0 0 1;
     0 0 0 0 0 0 0 0 1 0;
     0 0 0 0 0 0 0 1 0 0;
     0 0 0 0 0 0 0 0 0 1;
     0 0 0 0 0 0 0 1 0 0;
     0 0 0 0 0 0 0 0 0 0;
     0 0 0 1 0 1 0 0 0 0;
     1 0 1 0 0 0 0 0 0 0;
     0 1 0 0 1 0 0 0 0 0];
 
 C =[0 0 0 0 0 0 1 1 1 0;
     0 0 0 0 0 0 1 0 1 1;
     0 0 0 0 0 0 1 0 1 1;
     0 0 0 0 0 0 1 1 0 1;
     0 0 0 0 0 0 0 1 1 1;
     0 0 0 0 0 0 1 1 0 1;
     1 1 1 1 0 1 0 0 0 0;
     1 0 0 1 1 1 0 0 0 0;
     1 1 1 0 1 0 0 0 0 0;
     0 1 1 1 1 1 0 0 0 0];




 prnt1 = "Calculating eigenvalue vector...";
 partition = "-----------------------";
 disp(prnt1)
 disp(partition)
 EigenvalueVector = eig(C)
 prnt2 = "Sorted Eigenvalue vector:";
 sorted = sort(EigenvalueVector);
 disp(prnt2)
 disp(sorted)
 disp(partition)
 prnt3 = "Processing spectral gap:";
 disp(prnt3)
 siz = size(sorted);
 largest = sorted(siz(1));
 second = sorted(siz(1) - 1);
 spectral_gap = largest - second;
 disp(partition)
 disp(spectral_gap)
 
 
 