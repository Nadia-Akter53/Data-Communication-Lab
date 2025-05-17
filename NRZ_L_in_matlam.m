bits = [1 0 1 1 1 0 0 1];
bitrate = 1;
n = 1000;
T = length(bits) / bitrate;
N = n * length(bits);
dt = T / N;
t = 0 : dt : T - dt;

x = zeros(1, length(t));

for i = 1:length(bits)
    if bits(i) == 1
        x((i - 1) * n + 1 : i * n) = 1;
    else
        x((i - 1) * n + 1 : i * n) = -1;
    end
end

plot(t, x, 'LineWidth', 3);
hold on
plot([0 T], [0 0], 'k', 'LineWidth', 1.5)
hold off
ylim([-1.5 1.5]);
xlabel('Time (s)');
ylabel('Amplitude');
title('NRZ-L Encoded Signal');
grid on;

counter = 0;
result = zeros(1, length(bits));

for i = 1:length(t)
    if t(i) > counter
        counter = counter + 1;
        if x(i) > 0
            result(counter) = 1;
        else
            result(counter) = 0;
        end
    end
end

disp('NRZ-L Decoding:');
disp(result);
