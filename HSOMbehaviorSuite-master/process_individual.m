function process_individual(subjectName)
load(subjectName)
close all
%% Generate SNR over trials plot
for trialNo = 1:length(obj.Trials)
    SNR(trialNo) = obj.Trials(trialNo).Parameters(10);
    Code(trialNo) = obj.Trials(trialNo).Code;
end
figure
plot(SNR)
xlabel('trial #')
ylabel('SNR')
%% Obtain psychometric curve from binary logistic regression
%fsigm = @(param,xval) param(1)+(param(2)-param(1))./(1+10.^((param(3)-xval)*param(4)));
S2inds = find((Code == 1) + (Code == 2));
isHit = Code == 1;
% fit binary logistic regression
x = SNR(S2inds);
y = isHit(S2inds);

mdl = fitglm(x, y, "Distribution", "binomial");
xplot = linspace(min(SNR),max(SNR),1000)'; % test data
yplot = predict(mdl,xplot);
[~,x50ind] = min(abs(yplot - 0.5));
x50 = xplot(x50ind);

[f,ax] = makeStandardFigure(1,[1 1]);
hold on
plot(x/10,y,'o')
plot(xplot/10,yplot);
xlabel('% SNR')
printFigure('Psychometric_Curve_LJS_021223_Randomized')
%% generate confusion matrix
targets = Code <= 2; %% S2 was played if Code indicates hit or miss
outputs = (Code == 1) + (Code == 4); %% S2 spout was selected if Code indicated hit or false alarm
plotconfusion(targets,outputs)
end