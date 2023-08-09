% 초기 차량 상태 설정
x = 0;
y = 0;
yaw = 0;
v = 5; 

% 지도 정보 설정 (임의의 예시 데이터)
map_xs = [0, 10, 20, 30, 40];
map_ys = [0, 5, 10, 5, 0];
map_yaws = [0, pi/3, -pi/7, -pi/5, 0];

% 시뮬레이션 파라미터 설정
dt = 0.1; % 시간 간격
sim_time = 10; % 시뮬레이션 시간

% 초기화
xs = [];
ys = [];

% 시뮬레이션 루프
for t = 0:dt:sim_time
    steer = stanley_control(x, y, yaw, v, map_xs, map_ys, map_yaws);
    
    % 차량 상태 업데이트
    updated_state = update_vehicle_model(x, y, yaw, v, steer);
    x = updated_state.x;
    y = updated_state.y;
    yaw = updated_state.yaw;
    v = updated_state.v;
    
    % 경로 저장
    xs = [xs x];
    ys = [ys y];
    
    % 시각화
    figure(1);
    clf;
    plot(map_xs, map_ys, 'bo', xs, ys, 'b--', xs(end), ys(end), 'ro'); % 지도 지점을 파란색 원으로, 차량 경로를 파란색 점선으로, 마지막 위치를 빨간색 원으로 표시
    hold on;
    quiver(x, y, cos(yaw), sin(yaw), 1, 'r'); % 차량 방향을 화살표로 표시
    xlabel('X');
    ylabel('Y');
    title('Stanley Control Algorithm');
    legend('Map Points', 'Vehicle Path', 'Last Position', 'Vehicle Direction');
    grid on;
    axis equal;
    hold off;
    
    pause(dt); % 시간 간격만큼 대기
end
