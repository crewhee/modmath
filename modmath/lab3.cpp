#include "lab3.hpp"
const long a = 83707104;
const long b = 69691223;
const long length = 8;
const long cutter = pow(10, (length/4));


//серединных квадратов
long square(long a){
    long long result = a * a;
    result = result / cutter;
    result = result % long((pow(10, length)));
    return result;
}

//серединных произведений
long mul(long a, long b){
    long long result = a * b;
    result = result / cutter;
    result = result % long((pow(10, length)));
    return result;
}

//перемешивания
long mix(long a){
    //левая часть
    long transporting_left = a / (cutter * cutter * cutter);
    long result_left = a * cutter;
    result_left += transporting_left;
    result_left = result_left % long(pow(10, length));
    //правая часть
    long transporting_right = a % cutter;
    long result_right = transporting_right * (cutter * cutter * cutter);
    result_right += (a % (cutter * cutter * cutter));
    //сложение
    long result = result_left + result_right;
    return result % (cutter * cutter * cutter * cutter);
}

//линейный конгруэнтный метод
const long m = pow(2, 31) - 1;
const long _b = 7;
const long k = 1220703125;

long lin_con(long a){
    long result = ((k * a) + _b) % m;
    return result;
}

bool has_77(long a){
    long cut = 100;
    while(a != 0){
        if((a % cut) == 7){
            return true;
        }
        a = a / cut;
    }
    return false;
}

bool has_777(long a){
    long cut = 1000;
    while(a != 0){
        if((a % cut) == 777){
            return true;
        }
        a = a / cut;
    }
    return false;
}

bool has_7777(long a){
    long cut = 10000;
    while(a != 0){
        if((a % cut) == 7777){
            return true;
        }
        a = a / cut;
    }
    return false;
}

double math_ozh(vector<double> a){
    double result = 0;
    for(int i = 0; i < a.size(); i++){
        result = result + a[i];
    }
    return result / a.size();
}

double dispersion(vector<double> a, double b){
    double result = 0;
    for(int i = 0; i < a.size(); i++){
        result += pow(a[i] - b, 2);
    }
    return result / a.size();
}

void output_random(){
    vector<long>square_res, mul_res, mix_res, lin_con_res;
    square_res.reserve(10);
    mul_res.reserve(10);
    mix_res.reserve(10);
    lin_con_res.reserve(10);
    double m_o = 0;
    for(int i = 0; i < 10; i++){
        square_res[i] = 0;
        mul_res[i] = 0;
        mix_res[i] = 0;
        lin_con_res[i] = 0;
    }
    
    int has_7[12];
    for(int i = 0; i < 12; i++){
        has_7[i] = 0;
    }
    
    vector<double>square_num, mul_num, mix_num, lin_con_num;
    square_num.resize(1000000);
    mul_num.resize(1000000);
    mix_num.resize(1000000);
    lin_con_num.resize(1000000);
    
    long temp = a;
    for(int i = 0; i < 1000000; i++){
        temp = square(temp);
        square_res[int(temp / (pow(10, length-1)))]++;
        square_num[i] = temp/pow(10, length);
        if(has_77(temp)){
            has_7[0]++;
        }
        if(has_777(temp)){
            has_7[1]++;
        }
        if(has_7777(temp)){
            has_7[2]++;
        }
    }
    
    for(int i = 0; i < 10; i++){
        printf("%li ", square_res[i]);
    }
    printf("\n Ожидание \n");
    m_o = math_ozh(square_num);
    printf("%f %f", m_o, dispersion(square_num, m_o));
    printf("\n");
    
    
    temp = a;
    long temp_a = a;
    long temp_b = b;
    for(int i = 0; i < 1000000; i++){
        temp = mul(temp_a, temp_b);
        temp_a = temp_b;
        temp_b = temp;
        mul_res[int(temp / pow(10, length-1))]++;
        mul_num[i] = temp / pow(10, length);
        if(has_77(temp)){
            has_7[3]++;
        }
        if(has_777(temp)){
            has_7[4]++;
        }
        if(has_7777(temp)){
            has_7[5]++;
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%li ", mul_res[i]);
    }
    printf("\n Ожидание \n");
    m_o = math_ozh(mul_num);
    printf("%f %f", m_o, dispersion(mul_num, m_o));
    printf("\n");
    
    
    temp = a;
    for(int i = 0; i < 1000000; i++){
        temp = mix(temp);
        mix_res[int(temp / pow(10, length-1))]++;
        mix_num[i] = temp / pow(10, length);
        if(has_77(temp)){
            has_7[6]++;
        }
        if(has_777(temp)){
            has_7[7]++;
        }
        if(has_7777(temp)){
            has_7[8]++;
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%li ", mix_res[i]);
    }
    printf("\n Ожидание \n");
    m_o = math_ozh(mix_num);
    printf("%f %f", m_o, dispersion(mix_num, m_o));
    printf("\n");
    
    temp = 7;
    for(int i = 0; i < 1000000; i++){
        temp = lin_con(temp);
        lin_con_res[temp / (pow(2,31)/10)]++;
        lin_con_num[i] = temp / pow(2, 31);
        if(has_77(temp)){
            has_7[9]++;
        }
        if(has_777(temp)){
            has_7[10]++;
        }
        if(has_7777(temp)){
            has_7[11]++;
        }
    }
    for(int i = 0; i < 10; i++){
        printf("%li ", lin_con_res[i]);
    }
    printf("\n Ожидание \n");
    m_o = math_ozh(lin_con_num);
    printf("%f %f", m_o, dispersion(lin_con_num, m_o));
    printf("\n");
    
    for(int i = 0; i < 11;){
        printf("%i ", has_7[i]);
        printf("%i ", has_7[i+1]);
        printf("%i ", has_7[i+2]);
        printf("\n");
        i = i + 3;
    }
    printf("\n");
}
