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
    waste_record_.push_back(record_to_add);
    if (&record_to_add == &waste_record_.back()) {
      return true;
    } else {
      return false;
    }
  }
  bool DeleteFoodWasteRecord(int index_of_record_to_remove) {
    FoodWastageRecord* record_to_remove_ptr =
        &waste_record_[index_of_record_to_remove];
    std::vector<FoodWastageRecord>::iterator record_to_remove_iterator =
        waste_record_.begin() + index_of_record_to_remove;
    waste_record_.erase(record_to_remove_iterator);
    if (record_to_remove_ptr != &waste_record_[index_of_record_to_remove]) {
      return true;
    } else {
      return false;
    }
  }
  std::vector<FoodWastageRecord> GetWasteRecord() const {
    return waste_record_;
  }
  void GenerateReport() {
    FoodWastageReport new_report(waste_record_);
    waste_report_ = new_report;
  }
  FoodWastageReport GetWasteReport() const { return waste_report_; }

 private:
  std::vector<FoodWastageRecord> waste_record_;
  FoodWastageReport waste_report_;
};

#endif