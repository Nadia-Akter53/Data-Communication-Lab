%% Initialization

bits = [1 0 1 1 1 0 0 1];

bitrate = 1;
n = 1000;
T = length(bits) / bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;

x = zeros(1, length(t));

%% Differential Manchester Encoding

current_level = 1;

for i = 1:length(bits)
    start_idx = (i-1)*n + 1;
    mid_idx = (i-1)*n + n/2;
    end_idx = i*n;
    
    if bits(i) == 0
        current_level = -current_level;
    end
    
    x(start_idx:mid_idx) = current_level;
    
    current_level = -current_level;
    
    x(mid_idx+1:end_idx) = current_level;
end

figure;
plot(t, x, 'LineWidth', 2);
title('Differential Manchester Encoded Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

%% Differential Manchester Decoding

decoded = zeros(1, length(bits));
prev_level = x(1);

for i = 1:length(bits)
    start_idx = (i-1)*n + 1;
    curr_level = x(start_idx);
    
    if curr_level ~= prev_level
        decoded(i) = 0;
    else
        decoded(i) = 1;
    end
    
    prev_level = x(i*n);
end

disp('Original bits:');
disp(bits);
disp('Decoded bits from Differential Manchester:');
disp(decoded);

figure;
subplot(3,1,1);
stairs(0:length(bits)-1, bits, 'LineWidth', 2);
ylim([-0.5 1.5]);
title('Original Bits');
xlabel('Bit Number');
ylabel('Bit Value');
grid on;

subplot(3,1,2);
plot(t, x, 'LineWidth', 2);
ylim([-1.5 1.5]);
title('Differential Manchester Encoded Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

subplot(3,1,3);
stairs(0:length(decoded)-1, decoded, 'LineWidth', 2);
ylim([-0.5 1.5]);
title('Decoded Bits');
xlabel('Bit Number');
ylabel('Bit Value');
grid on;
