function steer = stanley_control(x, y, yaw, v, map_xs, map_ys, map_yaws)
    % 스탠리 제어 알고리즘 구현
    
    % 파라미터 설정
    L = 2.875;   % 차량 전륜축에서 중심점까지의 거리
    k = 3.0;       % 횡방향 오차(Cross-Track Error, CTE)에 대한 제어 파라미터

    % 가장 가까운 지점 찾기
    min_dist = 1e9;   % 초기 최소 거리 설정
    min_index = 0;    % 초기 최소 거리 지점 인덱스 설정
    n_points = length(map_xs);   % 지도 상의 지점 개수

    % 차량 전방의 좌표 계산
    front_x = x + L * cos(yaw);
    front_y = y + L * sin(yaw);

    % 지도 상의 각 지점과의 거리 계산
    for i = 1:n_points
        dx = front_x - map_xs(i);
        dy = front_y - map_ys(i);
        dist = sqrt(dx * dx + dy * dy);
        if dist < min_dist
            min_dist = dist;
            min_index = i;
        end
    end

    % 횡방향 오차(Cross-Track Error, CTE) 계산
    map_x = map_xs(min_index);
    map_y = map_ys(min_index);
    map_yaw = map_yaws(min_index);
    dx = map_x - front_x;
    dy = map_y - front_y;

    perp_vec = [cos(yaw + pi/2), sin(yaw + pi/2)];   % 방향벡터 계산
    cte = dot([dx, dy], perp_vec);   % 횡방향 오차(Cross-Track Error, CTE) 계산

    % 제어 수식 적용
    yaw_term = normalize_angle(map_yaw - yaw);   % 방향 각도 차이 계산
    cte_term = atan2(k * cte, v);   % 횡방향 오차(Cross-Track Error, CTE) 보정값 계산

    % 조향각 계산
    steer = yaw_term + cte_term;
    
    % 차량 모델 업데이트
    updated_state = update_vehicle_model(x, y, yaw, v, steer); % steer로 차량 모델 업데이트 호출
    x = updated_state.x;
    y = updated_state.y;
    yaw = updated_state.yaw;
    v = updated_state.v;
end
