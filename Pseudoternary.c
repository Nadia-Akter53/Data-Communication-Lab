bits = [1 0 0 1 0 1 0];

bitrate = 1;
n = 1000;
T = length(bits) / bitrate;
N = n * length(bits);
dt = T / N;
t = 0 : dt : T;
x = zeros(1, length(t));
lastbit = 1;

% Pseudoternary Encoding
for i = 1 : length(bits)
    if bits(i) == 0
        x((i - 1) * n + 1 : i * n) = -lastbit;
        lastbit = -lastbit;
    else
        x((i - 1) * n + 1 : i * n) = 0;
    end
end

% Plotting the waveform
plot(t, x, 'linewidth', 3);
xlabel('Time');
ylabel('Amplitude');
title('Pseudoternary Encoding');
grid on;
ylim([-1.5 1.5]);

% Decoding
counter = 0;
lastbit = 1;
result = zeros(1, length(bits));

for i = 1 : length(t)
    if t(i) > counter
        counter = counter + 1;
        if x(i) == -lastbit
            result(counter) = 0;
            lastbit = -lastbit;
        else
            result(counter) = 1;
        end
    end
end

disp('Decoded bit stream:');
disp(result);
