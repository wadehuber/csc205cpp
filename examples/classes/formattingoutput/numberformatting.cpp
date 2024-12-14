#include <iostream>
#include <iomanip>
#include <locale>

// Custom currency formatter to ensure proper money formatting
class money_formatter : public std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ','; }
    std::string do_grouping() const override { return "\003"; }
};

int main() {
    const double INCOME_TAX_RATE = 0.20;  // 20% income tax
    
    // Set up locale for money formatting
    std::locale money_locale(std::locale(), new money_formatter());
    std::cout.imbue(money_locale);
    
    int salary = 75000;
    double weeklyWage = salary / 52.0;
    double taxes = weeklyWage * INCOME_TAX_RATE;
    
    // Format currency with $ symbol, commas, and 2 decimal places
    auto formatMoney = [](double amount) {
        std::stringstream ss;
        ss << "$" << std::fixed << std::setprecision(2) << amount;
        return ss.str();
    };
    
    // Format percentage with % symbol and no decimal places
    auto formatPercent = [](double value) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(0) << (value * 100) << "%";
        return ss.str();
    };
    
    // Print formatted values
    std::cout << "Yearly salary: " << formatMoney(salary) << std::endl;
    std::cout << "Weekly pay: " << formatMoney(weeklyWage) << std::endl;
    std::cout << "Taxes: " << formatMoney(taxes) << " at " 
              << formatPercent(INCOME_TAX_RATE) << std::endl;
    
    return 0;
}
