#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

// ����һ��ָ����Χ�ڵ��������
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// ������ת��Ϊ�ַ���
string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}

// ���ɼӷ�����ʽ
string generateAdditionExpression(int grade) {
    int num1 = generateRandomNumber(1, grade == 1 ? 20 : (grade == 2 ? 50 : 1000));
    int num2 = generateRandomNumber(1, grade == 1 ? 20 : (grade == 2 ? 50 : 1000));
    return intToString(num1) + " + " + intToString(num2);
}

// ���ɼ�������ʽ
string generateSubtractionExpression(int grade) {
    int num1 = generateRandomNumber(1, grade == 1 ? 20 : (grade == 2 ? 50 : 1000));
    int num2 = generateRandomNumber(1, grade == 1 ? 20 : (grade == 2 ? 50 : 1000));
    return intToString(num1) + " - " + intToString(num2);
}

// ���ɳ˷�����ʽ
string generateMultiplicationExpression(int grade) {
    int num1 = generateRandomNumber(1, grade == 3 ? 1000 : 100);
    int num2 = generateRandomNumber(1, grade == 3 ? 1000 : 100);
    return intToString(num1) + " * " + intToString(num2);
}

// ���ɳ�������ʽ
string generateDivisionExpression(int grade) {
    int num1 = generateRandomNumber(1, grade == 4 ? 100 : 1000);
    int num2 = generateRandomNumber(1, grade == 4 ? 100 : 1000);
    return intToString(num1) + " / " + intToString(num2);
}

// ���ɻ������ʽ
string generateMixedExpression(int grade) {
    // ���ȷ�����������
    int num_operators = 3;
    if (grade >= 4 && grade <= 6) {
        num_operators = generateRandomNumber(3, 5);
    }
    
    string expression;
    for (int i = 0; i < num_operators; ++i) {
        // ���ѡ�������
        int op = generateRandomNumber(0, 3);
        switch(op) {
            case 0: // �ӷ�
                expression += generateAdditionExpression(grade);
                break;
            case 1: // ����
                expression += generateSubtractionExpression(grade);
                break;
            case 2: // �˷�
                expression += generateMultiplicationExpression(grade);
                break;
            case 3: // ����
                expression += generateDivisionExpression(grade);
                break;
        }
        expression += " ";
    }
    return expression;
}
#include <cassert>

// ���Ժ���
void test() {
    // ���� generateRandomNumber ����
    assert(generateRandomNumber(1, 10) >= 1 && generateRandomNumber(1, 10) <= 10);
    assert(generateRandomNumber(100, 200) >= 100 && generateRandomNumber(100, 200) <= 200);

    // ���� intToString ����
    assert(intToString(123) == "123");
    assert(intToString(456) == "456");

    // ���� generateAdditionExpression ����
    assert(generateAdditionExpression(1).find("+") != string::npos);
    assert(generateAdditionExpression(2).find("+") != string::npos);

    // ���� generateSubtractionExpression ����
    assert(generateSubtractionExpression(1).find("-") != string::npos);
    assert(generateSubtractionExpression(2).find("-") != string::npos);

    // ���� generateMultiplicationExpression ����
    assert(generateMultiplicationExpression(3).find("*") != string::npos);

    // ���� generateDivisionExpression ����
    assert(generateDivisionExpression(4).find("/") != string::npos);

    // ���� generateMixedExpression ����
    assert(generateMixedExpression(4).find_first_of("+-*/") != string::npos);

    // ����������
    // ������������Ҫ���û����������Խ����Զ����ԣ�����ʡ��

    cout << "���в���ͨ��!" << endl;
}




int main() {
    srand(time(0)); // ��ʼ�����������
    
    int grade, num_questions;
    char continue_choice;
    
    do {
        cout << "�������꼶��1-6����";
        cin >> grade;
        cout << "��������Ŀ������";
        cin >> num_questions;
        
        cout << "���ɵ�" << grade << "�꼶��" << num_questions << "����Ŀ���£�" << endl;
        for (int i = 0; i < num_questions; ++i) {
            string expression;
            if (grade == 1 || grade == 2) {
                expression = generateAdditionExpression(grade);
            } else if (grade == 3) {
                int op = generateRandomNumber(0, 1);
                if (op == 0) {
                    expression = generateAdditionExpression(grade);
                } else {
                    expression = generateSubtractionExpression(grade);
                }
            } else {
                expression = generateMixedExpression(grade);
            }
            cout << expression << endl;
        }
        
        cout << "�Ƿ����������Ŀ��(y/n): ";
        cin >> continue_choice;
    } while (continue_choice == 'y' || continue_choice == 'Y');
     test(); // ���в���
    return 0;
}

