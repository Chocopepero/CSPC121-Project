#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_

// Samuel Kim
// CPSC 121L - 02
// 2023-11-09
// samkunkim@csu.fullerton.edu
// @ChocoPepero

#include <iostream>
#include <vector>

#include "food_wastage_record.h"

class FoodWastageReport {
 public:
  void GenerateCommonWasteFood(const std::vector<FoodWastageRecord>&);
  void GenerateCommonWasteMeals(const std::vector<FoodWastageRecord>&);
  void CalculateCost(const std::vector<FoodWastageRecord>&);
  void GenerateCommonReason(const std::vector<FoodWastageRecord>&);
  void GenerateCommonMechOfDisposal(const std::vector<FoodWastageRecord>&);
  void GenerateSuggestedStrats();
  std::vector<std::string> GetCommonWasteFoods() const {
    return common_waste_foods_;
  }
  std::vector<std::string> GetCommonWasteMeals() const {
    return common_waste_meals_;
  }
  double GetTotalCost() const { return total_cost_; }
  std::vector<std::string> GetCommonReason() const { return common_reason_; };
  std::vector<std::string> GetCommonMechanismDisposal() const {
    return common_mechanism_disposal_;
  }
  std::vector<std::string> GetSuggestedStrats() const { suggested_strats_; }

 private:
  std::vector<std::string> common_waste_foods_;
  std::vector<std::string> common_waste_meals_;
  double total_cost_;
  std::vector<std::string> common_reason_;
  std::vector<std::string> common_mechanism_disposal_;
  std::vector<std::string> suggested_strats_;
};

#endif