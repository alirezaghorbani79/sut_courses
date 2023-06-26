function AM_Modulation(m, fm, Am, fc, Ac)
    

    % ====== Names of group members ======
    % ====== Matin Golpaygani ============
    % ====== Alireza Ghorbani ============
    % ====== Reza Adinepour   ============
    
    
    % Inputs of AM_Modulation Function (m, fm, Am, fc, Ac) for Example: AM_Modulation(1, 2000, 5, 30000, 5)
    % m = AM modulation Scale. (0 < m < 1 (for example: m = 1 means 100% modulation))
    % fm = Message Signal Frequency
    % Am = Amplitude of Message signal
    % fc = Carrier Frequency
    % Am = Amplitude of Carrier signal
    

    %% ===================== Define AM modulation Scale =====================
    
    if (m < 0 || m > 1)
        error('m should be less than or equal to one and geter than to zero'); 
    end

    %% ===================== Create Message signal =====================
    
    Ta = 1 / fm; %Time period of Message signal
    t = 0:Ta/999:6*Ta; % Total time Scale for simulation
    ym = Am * cos(2*pi*fm*t); % Eqation of Message signal
    figure(1);subplot(3, 1, 1);plot(t, ym);grid on; % Graphical representation of Message signal
    title ('Message Signal');xlabel ('time(sec)');ylabel ('Amplitud(volt)');

    %% ===================== Create carrier signal =====================

    Tc = 1 / fc; %Time period of carrier signal
    yc = Ac*cos(2*pi*fc*t); %Eqation of carrier signal
    subplot(3, 1, 2);plot(t, yc);grid on; %Graphical representation of carrier signal
    title ('Carrier Signal');xlabel ('time(sec)');ylabel ('Amplitud(volt)');

    %% ===================== AM Modulation =====================

    y = Ac*(1+m*cos(2*pi*fm*t)).*cos(2*pi*fc*t); % Equation of Amplitude
    subplot(3, 1, 3);plot(t, y, t, Ac.*(1+m*cos(2*pi*fm*t)), 'r', t, -Ac.*(1+m*cos(2*pi*fm*t)), 'r'); %Graphical representation of AM signal
    title ('Amplitude Modulated signal (Standard AM Signal)');xlabel ('time(sec)');ylabel ('Amplitud(volt)');grid on;
end