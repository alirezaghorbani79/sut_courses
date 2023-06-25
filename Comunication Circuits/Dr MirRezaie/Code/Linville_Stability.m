clear;clc;close all;

Ytr = input('enter admittance matrix(Ytr): ');
C = (abs(Ytr(1, 2)*Ytr(2, 1))) / (2*real(Ytr(1, 1))*real(Ytr(2, 2)) - real(Ytr(1, 2)*Ytr(2, 1))) ;
fprintf('\nC = %f\n\n', C);
if( (real(Ytr(1, 1)) > 0) && (real(Ytr(2, 2)) > 0) &&  (C >= 0 && C <= 1) )
    disp('stable');
else
    disp('unstable');
end


%[2.7+6.8j 0-0.5j ; 53-22j 0.1+1.5j]