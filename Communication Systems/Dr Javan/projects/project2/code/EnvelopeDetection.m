function EnvelopeDetection(fm, fc, ka)

    % Inputs of EnvelopeDetection Function (fm, fc, ka) for Example: EnvelopeDetection(2000, 30000, 1)
    % fm = Message Signal Frequency
    % fc = Carrier Frequency
    % ka = Sensitivity Factor
    
    tau_min = 1 / fc; %Lower bound of time constant Tc
    tau_max = 1 / fm; %Upper bound of time constant Tm
    Tc = 10^(-6); %Sampling time of tau
    tau = tau_min:Tc:tau_max;
    num_tau = length(tau);
    Ts = tau_min / 100; %Sampling time
    t = 0:Ts:2*tau_max;
    num_pts = length(t);
    Envelope_Signal = 1 + ka*cos(2*pi*fm*t);
    Modulated_Signal = Envelope_Signal.*cos(2*pi*fc*t);

    for i = 1:num_tau %Simulation for all values of tau starts here
        output_signal(1, 1) = 1 + ka;
        for n = 1:num_pts-1
            if output_signal(1, n) < Modulated_Signal(1,n)
                output_signal(1,n+1)= Modulated_Signal(1, n);
            else
                output_signal(1, n+1) = output_signal(1, n)*exp(-Ts / tau(1, i));
            end
        end
%         mse(1, i)=(norm((output_signal - Envelope_Signal).^2))/num_pts; %MSE Calculation
    end
    
%     [~, TauOptimum] = min(mse);
    
     output_signal(1, 1) = 1 + ka;
%     for n = 1:num_pts-1
%         if output_signal(1, n) < Modulated_Signal(1, n)
%             output_signal(1, n + 1) = Modulated_Signal(1, n + 1);
%         else
%             output_signal(1, n + 1) = output_signal(1, n)*exp(-Ts/tau(1, TauOptimum));
%         end
%     end
    %% Plots Modulated signal and output signal for optimum value of Tau
    figure(2);plot(t, Modulated_Signal); 
    hold on; 
    plot(t, output_signal, 'r', 'linewidth', 2);grid on;
    title('AM waveform and envelope detector output for \tau_o');xlabel('time(sec)');ylabel('Amplitud(volt)');
end