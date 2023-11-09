#ifndef FOOD_WASTAGE_RECORD_H_
#define FOOD_WASTAGE_RECORD_H_
#include <iostream>

// Please fill in below.
// <Your name>
// <Your section number> (e.g. CPSC 121L-01)
// <Date>
// <Your csu.fullerton.edu email>
// <Your GitHub username>

class FoodWastageRecord {
 public:
  std::string GetDate() const { return date_; }
  std::string GetMeal() const { return meal_; }
  std::string GetFoodName() const { return food_name_; }
  double GetQuantityOffWaste() const { return quantity_of_waste_; }
  std::string GetWasteReason() const { return waste_reason_; }
  std::string GetDisposalMethod() const { return disposal_method_; }
  double GetCost() const { return cost_; }
  void SetDate(const std::string &date) { date_ = date; }
  void SetMeal(const std::string &meal) { meal_ = meal; }
  void SetFoodName(const std::string &food_name) { food_name_ = food_name; }
  void SetQuantityOfWaste(double quantity_of_waste) {
    quantity_of_waste_ = quantity_of_waste;
  }
  void SetWasteReason(const std::string &waste_reason) {
    waste_reason_ = waste_reason;
  }
  void SetDisposalMethod(const std::string &disposal_method) {
    disposal_method_ = disposal_method;
  }
  void SetCost(double cost) { cost_ = cost; }

 private:
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double quantity_of_waste_;
  std::string waste_reason_;
  std::string disposal_method_;
  double cost_;
};

#endif