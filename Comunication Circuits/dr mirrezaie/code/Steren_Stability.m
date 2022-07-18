clear;clc;close all;

Ytr = input('enter admittance matrix(Ytr): ');
M = Ytr(2, 1)*Ytr(1, 2);
K = ( 2*real(Ytr(1, 1))*real(Ytr(2, 2)) ) / ( real(M) + abs(M) );
fprintf('\nK = %f\n\n', K);
if( (real(Ytr(1, 1)) > 0) && (real(Ytr(2, 2)) > 0) &&  K > 1 )
    disp('stable');
else
    disp('unstable');
end

%[2.7+6.8j 0-0.5j ; 53-22j 0.1+1.5j]
