function [] = mae_rmse_figures()
    % MAE
    CCN_1D_MAE = load('CCN_1D_MAE.dat');
    CCN_2D_MAE = load('CCN_2D_MAE.dat');
    
    figure(1);
    plot(1 : size(CCN_1D_MAE), CCN_1D_MAE, 'r');
    hold on;
    plot(1 : size(CCN_2D_MAE), CCN_2D_MAE, 'b');
    legend('CCN 1D', 'CCN 2D');
    xlabel('Number of training epochs');
    ylabel('Testing errors');
    title('MAE');
    
    % RMSE
    CCN_1D_RMSE = load('CCN_1D_RMSE.dat');
    CCN_2D_RMSE = load('CCN_2D_RMSE.dat');
    
    figure(2);
    plot(1 : size(CCN_1D_RMSE), CCN_1D_RMSE, 'r');
    hold on;
    plot(1 : size(CCN_2D_RMSE), CCN_2D_RMSE, 'b');
    legend('CCN 1D', 'CCN 2D');
    xlabel('Number of training epochs');
    ylabel('Testing errors');
    title('RMSE');
end