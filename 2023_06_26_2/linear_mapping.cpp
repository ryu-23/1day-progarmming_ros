#include <stdio.h>

#define No_Calibration_Point 5

struct CalibrationData {
    double X[No_Calibration_Point];
    double y[No_Calibration_Point];
}cal_data;

double linear_mapping(double x, struct CalibrationData cal_data)
{
    // 입력 값이 X 범위 내에 있는지 확인
    if (x <= cal_data.X[0]) {
        // 데이터에 없는 구간일 경우, 0번째와 1번째 데이터로 선형 방정식 사용
        double x1 = cal_data.X[0];
        double x2 = cal_data.X[1];
        double y1 = cal_data.y[0];
        double y2 = cal_data.y[1];
        double y = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));
        return y;
    }
    else if (x >= cal_data.X[No_Calibration_Point - 1]) {
        // 데이터에 없는 구간일 경우, N-2번째와 N-1번째 데이터로 선형 방정식 사용
        double x1 = cal_data.X[No_Calibration_Point - 2];
        double x2 = cal_data.X[No_Calibration_Point - 1];
        double y1 = cal_data.y[No_Calibration_Point - 2];
        double y2 = cal_data.y[No_Calibration_Point - 1];
        double y = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));
        return y;
    }

    // 입력 값이 X 범위 내에서 어느 구간에 속하는지 찾기
    int i;
    for (i = 0; i < No_Calibration_Point - 1; i++) {
        if (x >= cal_data.X[i] && x < cal_data.X[i + 1]) {
            break;
        }
    }

    // 선형 보간을 통해 출력 값 계산
    double x1 = cal_data.X[i];
    double x2 = cal_data.X[i + 1];
    double y1 = cal_data.y[i];
    double y2 = cal_data.y[i + 1];
    double y = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));

    return y;
}

int main()
{
    cal_data = {
        //{0.0, 255.75, 511.5, 767.25, 1023.0},  // X 범위
        {0.0, 1.0, 2.0, 3.0, 4.0},
        {-30.0, -15.0, 0.0, 15.0, 30.0}  // y 값
    };

    double x = -2;
    double mapped_value = linear_mapping(x, cal_data);
    printf("Mapped value: %.2f\n", mapped_value);

    return 0;
}
