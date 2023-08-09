function angle = normalize_angle(angle)
    while angle > pi
        angle = angle - 2.0 * pi;
    end

    while angle < -pi
        angle = angle + 2.0 * pi;
    end
end