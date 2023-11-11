#ifndef FOOD_WASTAGE_TRACKER_H_
#define FOOD_WASTAGE_TRACKER_H_

// Samuel Kim
// CPSC 121L - 02
// 2023-11-09
// samkunkim@csu.fullerton.edu
// @ChocoPepero

#include <iostream>
#include <vector>

#include "food_wastage_report.h"

class FoodWastageTracker {
 public:
  bool AddFoodWasteRecord(const FoodWastageRecord& record_to_add) {
    bool duplicate_exists{false};
    for (FoodWastageRecord records_in_vector : waste_record_) {
      if (records_in_vector == record_to_add) {
        duplicate_exists = true;
      }
    }
    if (!duplicate_exists) {
      waste_record_.push_back(record_to_add);
      return duplicate_exists;
    }
    return !duplicate_exists;
  }
  bool DeleteFoodWasteRecord(FoodWastageRecord record_to_remove) {
    bool duplicate_exists{false};
    std::vector<FoodWastageRecord>::iterator remove_itr = waste_record_.begin();
    for (FoodWastageRecord records_in_vector : waste_record_) {
      if (records_in_vector == record_to_remove) {
        duplicate_exists = true;
        break;
      }
      remove_itr++;
    }
    if (duplicate_exists) {
      waste_record_.erase(remove_itr);
      return duplicate_exists;
    }
    return duplicate_exists;
  }
  std::vector<FoodWastageRecord> GetWasteRecord() const {
    return waste_record_;
  }
  void GenerateReport() {
    waste_report_.GenerateCommonWasteFood(waste_record_);
    waste_report_.GenerateCommonWasteMeals(waste_record_);
    waste_report_.CalculateCost(waste_record_);
    waste_report_.GenerateCommonReason(waste_record_);
    waste_report_.GenerateCommonMechOfDisposal(waste_record_);
    waste_report_.GenerateSuggestedStrats();
  }
  FoodWastageReport GetWasteReport() const { return waste_report_; }

 private:
  std::vector<FoodWastageRecord> waste_record_;
  FoodWastageReport waste_report_;
};

#endif