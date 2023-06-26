clear;clc;close all;


t = -10:0.001:10;
x = SS_u(t) + SS_r(t-2) - SS_u(t-3) - SS_r(t-4); %input signal
x = [1 4 4 5];
xk = zeros(1, length(x))
for k = 0:length(x)-1
    for n=0:length(x)-1
        xk(k+1) = xk(k+1) + x(n+1)*exp( ((-j)*2*pi*k*n)/ length(x) );
    end
end

figure(1);stem(abs(xk));
figure(2);stem(abs(fft(x)));