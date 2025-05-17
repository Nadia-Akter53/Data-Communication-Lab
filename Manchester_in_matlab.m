% Manchester Encoding and Decoding in MATLAB
clc; clear; close all;

% Input binary data (you can change this)
data = [1 0 1 1 0 0 1 0];

% Parameters
bitRate = 1;          % bits per second (for time axis scaling)
Fs = 100;             % Sampling frequency (samples per bit)
Tb = 1/bitRate;       % bit duration
t = 0:1/Fs:Tb-1/Fs;   % time vector for one bit

% Manchester Encoding:
% Encoding rule:
% bit=1 -> high to low transition (1->0)
% bit=0 -> low to high transition (0->1)
encodedSignal = [];
for bit = data
    if bit == 1
        % high (1) first half, low (0) second half
        encodedSignal = [encodedSignal ones(1,length(t)/2) zeros(1,length(t)/2)];
    else
        % low (0) first half, high (1) second half
        encodedSignal = [encodedSignal zeros(1,length(t)/2) ones(1,length(t)/2)];
    end
end

% Time axis for entire signal
t_encoded = 0:1/Fs:Tb*length(data) - 1/Fs;

% Manchester Decoding:
% For each bit duration, check the transition:
% 1->0 means bit=1
% 0->1 means bit=0
decodedData = zeros(1,length(data));
samplesPerBit = length(t_encoded)/length(data);

for i = 1:length(data)
    % extract samples for this bit
    segment = encodedSignal((i-1)*samplesPerBit+1 : i*samplesPerBit);
    firstHalf = segment(1:samplesPerBit/2);
    secondHalf = segment(samplesPerBit/2+1:end);
    
    % Decode based on transition
    if mean(firstHalf) > mean(secondHalf)
        decodedData(i) = 1;
    else
        decodedData(i) = 0;
    end
end

% Plotting
figure;

subplot(3,1,1);
stairs(0:length(data)-1, data, 'LineWidth', 2);
ylim([-0.5 1.5]);
title('Original Data');
xlabel('Bit Number');
ylabel('Bit Value');
grid on;

subplot(3,1,2);
plot(t_encoded, encodedSignal, 'LineWidth', 2);
ylim([-0.5 1.5]);
title('Manchester Encoded Signal');
xlabel('Time (seconds)');
ylabel('Amplitude');
grid on;

subplot(3,1,3);
stairs(0:length(decodedData)-1, decodedData, 'LineWidth', 2);
ylim([-0.5 1.5]);
title('Decoded Data from Manchester Signal');
xlabel('Bit Number');
ylabel('Bit Value');
grid on;

% Display decoded data in Command Window
disp('Original Data:');
disp(data);
disp('Decoded Data:');
disp(decodedData);
