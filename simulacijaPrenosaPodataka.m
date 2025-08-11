clc; clear;

figure('Color','white');
axis([-1 11 -1 3]);
axis off;
hold on;

% Crtamo CPU i Disk
rectangle('Position',[0 0 2 1],'FaceColor',[0.6 0.9 1],'EdgeColor','k'); % CPU
text(0.5, 0.4, 'CPU', 'FontSize', 12, 'FontWeight','bold');

rectangle('Position',[8 0 2 1],'FaceColor',[1 0.8 0.8],'EdgeColor','k'); % HDD
text(8.5, 0.4, 'HDD', 'FontSize', 12, 'FontWeight','bold');

% Crtamo sabirnicu
plot([2 8], [0.5 0.5], 'k--', 'LineWidth', 2);
text(4.5, 0.7, 'SATA Sabirnica', 'FontSize', 10, 'Color', 'k');

% Animacija prenosa - 3 zahtjeva (različit prioritet)
prioriteti = ["nizi", "visi", "nizi"];
boje = {'[0.8 0.8 0.8]', '[0.4 0.4 1]', '[0.8 0.8 0.8]'}; % bijela/plava

for i = 1:3
    % Iscrtavanje strelice
    strelica = annotation('textarrow', 'String', ...
        sprintf('Proces %d (%s prioritet)', i, prioriteti(i)), ...
        'FontSize', 10, 'Color', 'k', ...
        'HeadStyle', 'vback3', ...
        'LineWidth', 2);
    
    % Animacija kretanja od CPU do HDD
    for x = 2:0.2:8
        p = fill([x x+0.5 x+0.5 x], [1.2 1.2 1.7 1.7], eval(boje{i}));
        pause(0.05);
        delete(p);
    end

    % Buzzer signal
    text(4.5, 2, 'Buzzer: prijenos završen!', 'Color','r','FontSize',10, 'FontWeight','bold');
    sound(sin(1:300)); %zvuk

    pause(1);
    cla; % brišemo sve osim CPU i HDD
    rectangle('Position',[0 0 2 1],'FaceColor',[0.6 0.9 1],'EdgeColor','k'); % CPU
    text(0.5, 0.4, 'CPU', 'FontSize', 12, 'FontWeight','bold');

    rectangle('Position',[8 0 2 1],'FaceColor',[1 0.8 0.8],'EdgeColor','k'); % HDD
    text(8.5, 0.4, 'HDD', 'FontSize', 12, 'FontWeight','bold');
    plot([2 8], [0.5 0.5], 'k--', 'LineWidth', 2);
    text(4.5, 0.7, 'SATA Sabirnica', 'FontSize', 10, 'Color', 'k');
end

text(3, -0.5, 'Simulacija završena: svi procesi su prenijeli podatke.', ...
    'FontSize', 12, 'Color', 'b');
