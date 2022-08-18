#include <iostream>
#include "LinkedList.hpp"
#include "DynamicArray.hpp"
#include "ComplexNumbers.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "QuadMatrix.hpp"
#include "Polynomial.hpp"
#include "Menu.hpp"
#include "Test.hpp"
int main() {









    /*
    int massive[4] ={1,2,3,4};
    auto* lls = new LinkedListSequence<int> (massive,4);

    float massive_float[4] = {1.25,2.25,3.55,4.75};
    auto* array = new ArraySequence<float> (massive_float,4);
    int t;

    ArraySequence<int> as(massive,3);
    t = as.GetLength();
    std::cout << "Sequence Array getlength "<<t << std::endl;

    t = as.Get(2);
    std::cout << "Sequence Array get [2] "<<t << std::endl;
    as.Append(1213);
    t = as.Get(3);
    std::cout << "Sequence Array get [3], after append \"3\" "<<t << std::endl;
    as.Prepend (-123123);
    t = as.Get(0);
    std::cout << "Sequence Array get [0],after prepend \"-123123\" "<<t << std::endl;
    as.InsertAt(4,3);
    t = as.Get(3);
    std::cout << "Sequence Array get [3],after insert \"4\" "<<t << std::endl;
    try{
        as.InsertAt(100,100);
    }catch(IndexOutOfRange& e){
        std::cout << "Sequence Array inserting wrong index failed successful " << std::endl;
    }
    Sequence<int>* sub_as;
    try{
        sub_as = as.GetSubsequence(0,100);
    }catch(IndexOutOfRange& e){
        std::cout << "Getting wrong index subsequence failed good "<< std::endl;
    }
    sub_as = as.GetSubsequence(0,2);
    std::cout << "Getting subsequence was good "<< std::endl;
    t = sub_as->GetLength();
    std::cout << "SubSequence Array get-length "<<t << std::endl;
    t = sub_as->Get(0);
    std::cout << "SubSequence Array get [0] "<<t << std::endl;
    t = sub_as->GetFirst();
    std::cout << "SubSequence Array getfirst "<<t << std::endl;
    t = sub_as->Get(1);
    std::cout << "SubSequence Array get [1] "<<t << std::endl;
    t = sub_as->Get(2);
    std::cout << "SubSequence Array get [2] "<<t << std::endl;
    t = sub_as->GetLast();
    std::cout << "SubSequence Array getlast "<<t << std::endl;
    sub_as = sub_as->Concat(lls);
    std::cout << "SubSequence Array concating linked list sequence with length - "<<sub_as->GetLength() << std::endl;
    std::cout << sub_as->Get(0)<<" "<<sub_as->Get(1) <<" "<<sub_as->Get(2) <<" "<<sub_as->Get(3) <<" "<<sub_as->Get(4) <<" "<<sub_as->Get(5) <<" "<<sub_as->Get(6) << std::endl;


    LinkedListSequence<float> list(massive_float, 3);
    t = list.GetLength();

    std::cout << "Sequence Linked list getlength "<<t << std::endl;
    float t1;
    t1 = list.Get(2);
    std::cout << "Sequence Linked list get [2] "<<t1 << std::endl;
    list.Append(1213);
    t1 = list.Get(3);
    std::cout << "Sequence Linked list get [3], after append "<<t1 << std::endl;
    list.Prepend (-123123);
    t1 = list.Get(0);
    std::cout << "Sequence Linked list get [0],after prepend "<<t1 << std::endl;
    list.InsertAt(4.333,3);
    t1 = list.Get(3);
    std::cout << "Sequence Linked list get [3],after insert "<<t1 << std::endl;
    try{
        list.InsertAt(100,100);
    }catch(IndexOutOfRange& e){
        std::cout << "Sequence Linked list inserting wrong index failed successful " << std::endl;
    }
    Sequence<float>* sub_list;
    try{
        sub_list = list.GetSubsequence(0,100);
    }catch(IndexOutOfRange& e){
        std::cout << "Getting wrong index subsequence failed good "<< std::endl;
    }
    sub_list = list.GetSubsequence(0,2);
    std::cout << "Getting subsequence was good "<< std::endl;
    t = sub_list->GetLength();
    std::cout << "SubSequence Linked list get-length "<<t << std::endl;
    t1 = sub_list->Get(0);
    std::cout << "SubSequence Linked list get [0] "<<t1 << std::endl;
    t1 = sub_list->GetFirst();
    std::cout << "SubSequence Linked list getfirst "<<t1 << std::endl;
    t1 = sub_list->Get(1);
    std::cout << "SubSequence Linked list get [1] "<<t1 << std::endl;
    t1 = sub_list->Get(2);
    std::cout << "SubSequence Linked list get [2] "<<t1 << std::endl;
    t1 = sub_list->GetLast();
    std::cout << "SubSequence Linked list getlast "<<t1<< std::endl;
    sub_list->Concat(array);
    std::cout << "SubSequence Linked list concating array sequence with length - "<<sub_as->GetLength() << std::endl;
    std::cout << sub_list->Get(0)<<" "<<sub_list->Get(1) <<" "<<sub_list->Get(2) <<" "<<sub_list->Get(3) <<" "<<sub_list->Get(4) <<" "<<sub_list->Get(5) <<" "<<sub_list->Get(6) << std::endl;
    ComplexNumber<int> int_complex1(1,-1);
    ComplexNumber<int> int_complex2(2,-2);
    ComplexNumber<int> int_complex3(3,-3);
    ComplexNumber<int> a4(4,-4);

    //ComplexNumber<int> complex_array[4];
    ComplexNumber<int> complex_array[] = {int_complex1,int_complex2,int_complex3,a4};
    auto* complex_sequence = new ArraySequence<ComplexNumber<int>> (complex_array,3);

    std::cout << "Getting from complex array element with index 1 "<< std::endl;
    print_complex(complex_sequence->Get(1));
    std::cout << "Getting from complex array first element then multipiying it by 123\nResult "<< std::endl;
    ComplexNumber<int> complex_for_test = complex_sequence->GetFirst()*123;

    print_complex(complex_for_test);
    std::cout << "First element "<< std::endl;
    print_complex(complex_sequence->GetFirst());

    std::cout << "(1-1i)-(2-2i) "<< std::endl;
    complex_for_test = int_complex1-int_complex2;


    print_complex(complex_for_test);
    std::cout << "(1-1i)+(2-2i) "<< std::endl;


    complex_for_test = int_complex1+int_complex2;
    print_complex(complex_for_test);
    std::cout << "(1-1i)*(2-2i) "<< std::endl;
    complex_for_test = int_complex1*int_complex2;
    print_complex(complex_for_test);
    QuadMatrix<float>FloatMatrix(sub_list,1);

    QuadMatrix<int>IntMatrix(sub_as,2);

    QuadMatrix<int>IntMatrixForTest;
    std::cout << "Sum of two matrixes,each one is equal to "<<std::endl;
    IntMatrixForTest = IntMatrix+IntMatrix;
    print_matrix(IntMatrix);
    std::cout << "\nResult "<< std::endl;
    print_matrix(IntMatrixForTest);
    std::cout << "\nResult minus base matrix "<<std::endl;
    IntMatrixForTest = IntMatrixForTest-IntMatrix;
    print_matrix(IntMatrixForTest);
    std::cout << "\nMatrix x matrix "<<std::endl;
    IntMatrixForTest = IntMatrixForTest*IntMatrix;
    print_matrix(IntMatrixForTest);
    std::cout<<"\n"<<std::endl;
    try{
        IntMatrix.swap_columns(1,100);
    }catch(MatrixError& e){
        std::cout << "Tried to swap columns with too much indexes "<<std::endl;
    }
    std::cout << "Swapping columns "<<std::endl;
    std::cout << "Was "<<std::endl;

    print_matrix(IntMatrix);
    IntMatrix.swap_columns(0,1);
    IntMatrixForTest = IntMatrix;
    std::cout << "Become "<<std::endl;
    print_matrix(IntMatrixForTest);
    try{
        IntMatrix.swap_rows(1,100);
    }catch(MatrixError& e){
        std::cout << "Tried to swap rows with too much indexes "<<std::endl;
    }
    std::cout << "Swapping rows "<<std::endl;
    std::cout << "Was "<<std::endl;

    print_matrix(IntMatrix);
    IntMatrix.swap_rows(0,1);
    IntMatrixForTest = IntMatrix;
    std::cout << "Become "<<std::endl;
    print_matrix(IntMatrixForTest);
    std::cout << "Norm of it is "<<IntMatrix.norm()<<std::endl;
    std::cout << "It, but multiplied by 2 "<<IntMatrix.norm()<<std::endl;
    IntMatrixForTest = IntMatrix*2;
    print_matrix(IntMatrixForTest);
    std::cout << "And first row multiplied by 300 "<<std::endl;
    IntMatrixForTest.mult_row(300,0);
    print_matrix(IntMatrixForTest);
    try{
        IntMatrixForTest.mult_column(0,1000);
    }catch(MatrixError& e){
        std::cout << "Tried to multiply column with wrong index "<<std::endl;
    }
    std::cout << "And first column multiplied by 0 "<<std::endl;
    IntMatrixForTest.mult_column(0,0);
    print_matrix(IntMatrixForTest);
    std::cout << "And adding first row multiplied by 3 to 2nd row "<<std::endl;
    IntMatrixForTest.add_multiplied_row(1,0,3);
    print_matrix(IntMatrixForTest);
    std::cout << "And adding 2nd column multiplied by 3 to first column "<<std::endl;
    IntMatrixForTest.add_multiplied_column(0,1,3);
    print_matrix(IntMatrixForTest);
    Polynomial<ComplexNumber<int>> pol_complex(complex_sequence);
    std::cout << "Created polynomial with following complex coefficents "<<std::endl;
    for (int i = 0;i<complex_sequence->GetLength();i++){
        std::cout<<pol_complex.Get(i)<<std::endl;
    }
    std::cout << "Calculating F(1-1i), F - our polynomial  "<<std::endl;
    std::cout<<pol_complex(int_complex1)<<std::endl;
    Polynomial<ComplexNumber<int>> pol_test(complex_sequence);
    try{
        pol_test(int_complex1);
    }catch(PolyError& e){
        std::cout << "tried to calculate value of an empty polynomial "<<std::endl;
    }

    std::cout << "1st Polynom multiplied by 1st polynom is 2nd polynom"<<std::endl;

    pol_test = pol_test*pol_complex;

    for(int i = 0;i<pol_test.GetSize();i++){

        std::cout<<pol_test.Get(i)<<std::endl;

    }
    std::cout << "1st Polynom plus 2nd polynom"<<std::endl;

    pol_test = pol_test+pol_complex;

    for(int i = 0;i<pol_test.GetSize();i++){
        std::cout<<pol_test.Get(i)<<std::endl;
    }
    std::cout << "Previous Polynom minus 1st polynom"<<std::endl;
    pol_test = pol_test-pol_complex;
    for(int i = 0;i<pol_test.GetSize();i++){
        std::cout<<pol_test.Get(i)<<std::endl;
    }
    pol_test = pol_complex(pol_complex);
    std::cout << "Composition of 1st Polynom & 1st polynom"<<std::endl;
    for(int i = 0;i<pol_test.GetSize();i++){
        std::cout<<pol_test.Get(i)<<std::endl;
    }*/
    int int_array1[] = {1, 2, 3};
    int int_array2[] = {3, 2, 1};
    Polynomial<int> int_pol1(int_array1, 3);
    Polynomial<int>int_pol2(int_array2, 3);
    Test<int> test_int(int_pol1, int_pol2);
    test_int.print_pols();
    test_int.PolynomialoperationsTest(2);
    test_int.ZeroOperationsTest(0);
    test_int.Exceptions();


    float float_array1[] = {1.5, 2.5, 3.5};
    float float_array2[] = {3.5, 2.5, 1.5};
    Polynomial<float> float_pol1(float_array1, 3);
    Polynomial<float>float_pol2(float_array2, 3);
    Test<float> test_float(float_pol1, float_pol2);
    test_float.print_pols();
    test_float.PolynomialoperationsTest(1.5);
    test_float.ZeroOperationsTest(0);
    test_float.Exceptions();

    ComplexNumber<int> int_complex_zero(0, 0);
    ComplexNumber<int> int_complex1(1, -1);
    ComplexNumber<int> int_complex2(2, -2);
    ComplexNumber<int> int_complex3(3, -3);
    ComplexNumber<int> int_complex_array1[] = {int_complex1, int_complex2, int_complex3};
    ComplexNumber<int> int_complex_array2[] = {int_complex3, int_complex2, int_complex1};
    Polynomial<ComplexNumber<int>> int_complex_pol1(int_complex_array1,3);
    Polynomial<ComplexNumber<int>> int_complex_pol2(int_complex_array2,3);
    Test<ComplexNumber<int>> test_int_complex(int_complex_pol1,int_complex_pol2);
    test_int_complex.print_pols();
    test_int_complex.PolynomialoperationsTest(int_complex1);
    test_int_complex.ZeroOperationsTest(int_complex_zero);
    test_int_complex.Exceptions();


    ComplexNumber<float> float_complex_zero(0, 0);
    ComplexNumber<float> float_complex1(1.5, -1.5);
    ComplexNumber<float> float_complex2(2.5, -2.5);
    ComplexNumber<float> float_complex3(3.5, -3.5);
    ComplexNumber<float> float_complex_array1[] = {float_complex1, float_complex2, float_complex3};
    ComplexNumber<float> float_complex_array2[] = {float_complex3, float_complex2, float_complex1};
    Polynomial<ComplexNumber<float>> float_complex_pol1(float_complex_array1,3);
    Polynomial<ComplexNumber<float>> float_complex_pol2(float_complex_array2,3);
    Test<ComplexNumber<float>> test_float_complex(float_complex_pol1,float_complex_pol2);
    test_float_complex.print_pols();
    test_float_complex.PolynomialoperationsTest(float_complex1);
    test_float_complex.ZeroOperationsTest(float_complex_zero);
    test_float_complex.Exceptions();

    int int_array_for_matrix_zero[] = {0, 0, 0, 0};
    int int_array_for_matrix1[] = {1, 1, 1, 1};
    int int_array_for_matrix2[] = {2,2,2, 2};
    int int_array_for_matrix3[] = {3, 3, 3, 3};
    QuadMatrix<int> int_matrix_zero(int_array_for_matrix_zero, 2);
    QuadMatrix<int> int_matrix1(int_array_for_matrix1, 2);
    QuadMatrix<int> int_matrix2(int_array_for_matrix2,2);
    QuadMatrix<int> int_matrix3(int_array_for_matrix3, 2);
    QuadMatrix<int> int_matrix_array1[] = {int_matrix1,int_matrix2,int_matrix3};
    QuadMatrix<int> int_matrix_array2[] = {int_matrix3,int_matrix2,int_matrix1};
    Polynomial<QuadMatrix<int>> int_matrix_pol1(int_matrix_array1,3);
    Polynomial<QuadMatrix<int>> int_matrix_pol2(int_matrix_array2,3);
    Test<QuadMatrix<int>> test_int_matrix(int_matrix_pol1,int_matrix_pol2);

    test_int_matrix.print_pols();
    test_int_matrix.PolynomialoperationsTest(int_matrix1);
    test_int_matrix.ZeroOperationsTest(int_matrix_zero);
    test_int_matrix.Exceptions();


    float float_array_for_matrix_zero[] = {0, 0, 0, 0};
    float float_array_for_matrix1[] = {1.5, 1.5, 1.5, 1.5};
    float float_array_for_matrix2[] = {2.5,2.5,2.5, 2.5};
    float float_array_for_matrix3[] = {3.5, 3.5, 3.5, 3.5};
    QuadMatrix<float> float_matrix_zero(float_array_for_matrix_zero, 2);
    QuadMatrix<float> float_matrix1(float_array_for_matrix1, 2);
    QuadMatrix<float> float_matrix2(float_array_for_matrix2,2);
    QuadMatrix<float> float_matrix3(float_array_for_matrix3, 2);
    QuadMatrix<float> float_matrix_array1[] = {float_matrix1,float_matrix2,float_matrix3};
    QuadMatrix<float> float_matrix_array2[] = {float_matrix3,float_matrix2,float_matrix1};
    Polynomial<QuadMatrix<float>> float_matrix_pol1(float_matrix_array1,3);
    Polynomial<QuadMatrix<float>> float_matrix_pol2(float_matrix_array2,3);
    Test<QuadMatrix<float>> test_float_matrix(float_matrix_pol1,float_matrix_pol2);

    test_float_matrix.print_pols();
    test_float_matrix.PolynomialoperationsTest(float_matrix1);
    test_float_matrix.ZeroOperationsTest(float_matrix_zero);
    test_float_matrix.Exceptions();



    InterfacePol* MenuInterface;

    int interface_type;
    int action_type;
    int programm = 1;
    std::string type_str;
    std::cout<<"1 Int polynomial \n2 Float polynomial\n3 Int complex polynomial \n4 Float complex polynomial\n5 Int square matrix polynomial \n6 Float square matrix polynomial\n7 End programm"<<std::endl;
    getline(std::cin, type_str);
    interface_type= stoi(type_str);
    switch(interface_type){
        case 1:
            MenuInterface = new IntPolInterface();
            break;
        case 2:
            MenuInterface = new FloatPolInterface();
            break;
        case 3:
            MenuInterface = new IntComplexPolInterface();
            break;
        case 4:
            MenuInterface = new FloatComplexPolInterface();
            break;
        case 5:
            MenuInterface = new IntQuadMatrixPolInterface();
            break;
        case 6:
            MenuInterface = new FloatQuadMatrixPolInterface();
            break;
        case 7:
            programm = 0;
            MenuInterface = nullptr;
            break;
        default:
            throw MenuError(WrongMenuInput);
    }

    Menu NewMenu(MenuInterface);
    while (programm){
        NewMenu.PrintPol();
        std::cout<<"1 Add polynomial\n2 Substract polynomial\n3 Multiply polynomial by polynomial\n4 Concatenate polynomial \n5 Multiply polynomial by number\n6 Show value\n7 Exit\n"<<std::endl;
        getline(std::cin, type_str);
        action_type= stoi(type_str);
        switch(action_type){
            case 1:
                std::cout<<"Adding polynomial"<<std::endl;
                NewMenu.AddPol();

                break;
            case 2:
                std::cout<<"Substracting polynomial"<<std::endl;
                NewMenu.SubstractPol();

                break;
            case 3:
                std::cout<<"Multiplying polynomial by polynomial"<<std::endl;
                NewMenu.MultiplyByPol();

                break;
            case 4:
                std::cout<<"Concatenating polynomial"<<std::endl;
                NewMenu.ConcatenatedFromPol();

                break;
            case 5:
                std::cout<<"Multiplying polynomial by number"<<std::endl;
                NewMenu.MultiplyByNumber();

                break;
            case 6:
                std::cout<<"Showing value"<<std::endl;
                NewMenu.ShowValue();

                break;
            case 7:
                programm = 0;

                break;
            default:
                throw MenuError(WrongMenuInput);
        }
    }
    return 0;
}
