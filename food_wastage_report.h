#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_

// Samuel Kim
// CPSC 121L - 02
// 2023-11-09
// samkunkim@csu.fullerton.edu
// @ChocoPepero

#include "food_wastage_record.h"
#include <vector>
#include <iostream>

class FoodWastageReport {
 public:
  void GenerateCommonWasteFood(std::vector<FoodWastageRecord>) {
    
  }
  void GenerateCommonWasteMeals(std::vector<FoodWastageRecord>);
  void CalculateCost(std::vector<FoodWastageRecord>);
  void GenerateReason(std::vector<FoodWastageRecord>);
  void GenerateCommonReason(std::vector<FoodWastageRecord>);
  void GenerateCommonMechOfDisposal(std::vector<FoodWastageRecord>);
  void GenerateSuggestedStrats(std::vector<FoodWastageRecord>);
  std::vector<std::string> GetCommonWasteFoods();
  std::vector<std::string> GetCommonWasteMeals();
  double GetTotalCost();
  std::vector<std::string> GetCommonReason();
  std::vector<std::string> GetCommonMechanismDisposal();
  std::vector<std::string> GetSuggestedStrats();

 private:
  std::vector<std::string> common_waste_foods_;
  std::vector<std::string> common_waste_meals_;
  double total_cost_;
  std::vector<std::string> common_reason_;
  std::vector<std::string> common_mechanism_disposal_;
  std::vector<std::string> suggested_strats_;
};

#endif