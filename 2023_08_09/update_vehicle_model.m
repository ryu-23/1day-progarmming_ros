function updated_state = update_vehicle_model(x, y, yaw, v, steer, a)
    % 파라미터 설정
    dt = 0.1;
    L = 2.875;
    max_steering = deg2rad(45);

    % steer와 a 값이 전달되지 않았을 경우 기본값으로 설정
    if nargin < 5
        steer = 0.0;
    end
    if nargin < 6
        a = 0.0;
    end

    % steer 값 클리핑
    steer = max(min(steer, max_steering), -max_steering);

    % 상태 업데이트
    x = x + v * cos(yaw) * dt;
    y = y + v * sin(yaw) * dt;
    yaw = yaw + v / L * tan(steer) * dt;
    yaw = mod(yaw, 2.0 * pi);
    v = v + a * dt;

    % 업데이트된 상태 반환
    updated_state = struct('x', x, 'y', y, 'yaw', yaw, 'v', v);
end
