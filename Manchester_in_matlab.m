%% Initialization

bits = [1 0 1 1 1 0 0 1];

bitrate = 1;
n = 1000;
T = length(bits) / bitrate;
N = n * length(bits);
dt = T / N;
t = 0:dt:T;

x = zeros(1, length(t));

%% Manchester Encoding

for i = 1:length(bits)
    start_idx = (i-1)*n + 1;
    mid_idx = (i-1)*n + n/2;
    end_idx = i*n;
    
    if bits(i) == 1
        x(start_idx:mid_idx) = 1;
        x(mid_idx+1:end_idx) = -1;
    else
        x(start_idx:mid_idx) = -1;
        x(mid_idx+1:end_idx) = 1;
    end
end

figure;
plot(t, x, 'LineWidth', 2);
title('Manchester Encoded Signal');
xlabel('Time (s)');
ylabel('Amplitude');
grid on;

%% Manchester Decoding

decoded = zeros(1, length(bits));

for i = 1:length(bits)
    mid_idx = (i-1)*n + n/2;
    
    if x(mid_idx) > 0
        decoded(i) = 1;
    else
        decoded(i) = 0;
    end
end

disp('Original bits:');
disp(bits);
disp('Decoded bits from Manchester:');
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
title('Manchester Encoded Signal');
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
