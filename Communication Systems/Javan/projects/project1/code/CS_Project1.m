clear;clc;close all;

% ====== Names of group members ======
% ====== Matin Golpaygani ============
% ====== Alireza Ghorbani ============
% ====== Reza Adinepour   ============



%% define system and input signal
t = -10:0.001:10;
% x = SS_u(t) + SS_r(t-2) - SS_u(t-3) - SS_r(t-4); %input signal
x = SS_pulse(t-3);
h = SS_pulse(t-3); % impulse response of system

figure(1);subplot(3,2,1);plot(t, x);title('input signal x(t)');
subplot(3,2,2);plot(t, h);title('impulse response h(t)');



%% calculate fourier transform usnig fft() function
X = fft(x); % fourier transform of x(t) -> X(f)
H = fft(h); % frequency response of system
Y_f = X.*H;
y_t = ifft(Y_f);

subplot(3,2,3);plot(abs(fftshift(X)));title('X(f)');
subplot(3,2,4);plot(abs(fftshift(H)));title('H(f)');
subplot(3,2,6);plot(abs(y_t));title('F inv {Y(f) = X(f).H(f)}');



%% calculate convolution usnig conv() function
y_conv = conv(x, h); % y(t) = x(t)*h(t)
t_conv = 2*t(1):0.001:2*t(end);

subplot(3,2,5);plot(t_conv, y_conv);title('y(t) = x(t)*h(t)');



%% calculate convolution without usnig conv() function
xConv = [x, zeros(1, length(h))]
hConv = [h, zeros(1, length(x))];
for i = 1:length(h)+length(x)-1
    yConv(i) = 0;
    for j = 1:length(x)
        if(i-j+1 > 0)
            yConv(i) = yConv(i) + (xConv(j) * hConv(i-j+1));
        else
            break;
        end
    end
end

figure(2);subplot(3,2,1);plot(t, x);title('input signal x(t)');
subplot(3,2,2);plot(t, h);title('impulse response h(t)');
subplot(3,2,3);plot(abs(fftshift(X)));title('X(f)');
subplot(3,2,4);plot(abs(fftshift(H)));title('H(f)');
subplot(3,2,5);plot(t_conv, yConv);title('y(t) = x(t)*h(t)');
subplot(3,2,6);plot(abs(y_t));title('F inv {Y(f) = X(f).H(f)}');  
