#include <iostream>
#include "Sales_item.h"

int p1_1 () {
  return 0;
}

int p1_2 () {
  return -1;
}

int p1_3_hello_world () {
  std::cout << "Hello World!" << std::endl;

  return 0;
}

int p1_4 () {
  std::cout << "2 3 相加：" << 2 + 3 << std::endl;
  std::cout << "3 6 相乘：" << 3 * 6 << std::endl;

  return 0;
}

int p1_5 () {
  std::cout << "5 3 相减：" << 5 - 3 << std::endl
  << "9 3 相除：" << 9 / 3 << std::endl;

  return 0;
}

int p1_6 () {
  int v1 = 66;
  int v2 = 88;
  // 原题不合法，不应该加封号
  std::cout << "The Sum of " << v1
            << " and " << v2
            << " is " << v1 + v2 << std::endl;
  return 0;
}

int p1_7 () {
  // 下面的注释是不合法的，被合法的行注释注释了
  // /**
  //  * /* asd */
  //  */
  return 0;
}

int p1_8 () {
  // 指出下列哪些输出语句是合法的（如果有的话）
  // 只有前两个是合法的
  std::cout << "/*";
  std::cout << "*/";
  // std::cout << /* "*/" */;
  // std::cout << /* "*/" /* "/*" */;
  return 0;
}

int p1_9_while () {
  int val = 50;
  int result = 0;

  while (val <= 100) {
    result += val;
    val++;
  }
  std::cout << "50 到 100的整数相加结果" << result << std::endl;
  return 0;
}

int p1_10 () {
  int val = 10;

  while (val >= 0) {
    std::cout << val << (val == 0 ? "" : ",");
    val--;
  }
  std::cout << std::endl;
  return 0;
}

int p1_11 () {
  int val1;
  int val2;

  std::cout << "请输入两个数字，将打印出两个数字之间的所有整数" << std::endl
    << "第一个整数：" << std::endl;
  std::cin >> val1;
  std::cout << "第二个整数：" << std::endl;
  std::cin >> val2;

  int min = val1 < val2 ? val1 : val2;
  int max = val1 > val2 ? val1 : val2;

  while (min <= max) {
    std::cout << min++ << ";";
  }
  std::cout << std::endl;
  return 0;
}

int p1_12_for () {
  int sum = 0;
  for (int i = -100; i <= 100; i++) {
    sum += i;
  }
  std::cout << "最终sum 结果为" << sum << std::endl;
  return 0;
}

int p1_13 () {
  int result = 0;

  for (int val = 50; val < 100; val++) {
    result += val;
  }

  std::cout << "50 到 100的整数相加结果" << result << std::endl;
  return 0;
}

int p1_14 () {
  // 对比：
  // for 循环可以把初始化、条件、动作一开始就编写好，while 容易遗漏，容易死循环
  return 0;
}

int p1_15 () {
  // 熟悉编译器生成的错误
  return 0;
}

int p1_16 () {
  int sum = 0;
  int value = 0;

  while (std::cin >> value) {
    sum += value;
    std::cout << "Sum is:" << sum << std::endl;
  }

  return 0;
}

int p1_17_18 () {
  int curVal = 0;
  int val = 0;

  if (std::cin >> curVal) {
    int cnt = 1;

    while (std::cin >> val) {
      if (curVal == val) {
        ++cnt;
      } else {
        std::cout << curVal << " BB: occurs " << cnt << " times." << std::endl;
        curVal = val;
        cnt = 1;
      }
    }
    std::cout << curVal << " AA: occurs " << cnt << " times." << std::endl;
  }

  return 0;
}

int p1_19 () {
  int min;
  int max;

  std::cout << "请输入两个数字，将打印出两个数字之间的所有整数" << std::endl
    << "第一个整数：" << std::endl;
  std::cin >> min;
  std::cout << "第二个整数：" << std::endl;
  std::cin >> max;

  if (min > max) {
    int temp = max;
    max = min;
    min = temp;
  }

  while (min <= max) {
    std::cout << min++ << ";";
  }
  std::cout << std::endl;
  return 0;
}

int p1_20_class () {
  Sales_item book;
  // 读入：ISBN号、售出册数、销售价格
  std::cin >> book;
  // 输出：ISBN号、售出册数、总销售额、平均价格
  std::cout << book << std::endl;
  return 0;
}

int p1_21 () {
  Sales_item item1, item2;
  std::cin >> item1;
  std::cin >> item2;
  std::cout << item1 + item2 << std::endl;
  return 0;
}

int p1_22 () {
  Sales_item sum_item;
  std::cin >> sum_item;

  Sales_item curItem;
  while (std::cin >> curItem) {
    sum_item += curItem;
  }

  std::cout << "All sale items:" << sum_item << std::endl;
  return 0;
}


int main () {
  p1_1();
  p1_2();
  p1_3_hello_world();
  p1_4();
  p1_5();
  p1_6();
  p1_7();
  p1_8();
  p1_9_while();
  p1_10();
  p1_11();
  p1_12_for();
  p1_13();
  p1_14();
  p1_15();
  p1_16();
  p1_17_18();
  p1_19();
  p1_20_class();
  p1_21();
  p1_22();

  return 0;
}
