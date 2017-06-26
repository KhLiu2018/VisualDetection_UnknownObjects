#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool stable_relation(Object o1, Object o2) {
    if (o1.centerX >= o2.leftX && o1.centerX <= o2.rightX) {
      return true;
    }
    return false;
}
bool isObjectsAdjacent(Object o1, Object o2) {
    if (o1.bottomY - o2.topY <= 2) {
      max_right = o1.rightX > o2.rightX ? o1.rightX : o2.rightX;
      min_left = o1.leftX < o2.leftX ? o1.leftX : o2.leftX;
      interval_o1 = o1.rightX - o1.leftX;
      interval_o2 = o2.rightx - o2.leftx;
      if (interval_o1 + interval_o2 < max_right - min_left) {
        return true;
      }
    }
    return false;
}
vector<int> searchSupportObject(int index, vector<Object> objectlist) {
    // if (index == objectlist.size()-1) {
    //   return NULL;
    // }
    vector<int> SupportIndex_objectlist;
    SupportIndex_objectlist.append(index);
    vector<int> AdjacentIndex_objectlist;
    for (int i = index + 1; i < objectlist.size(); i++) {
      if (isObjectsAdjacent(objectlist[index], objectlist[i])) {
          SupportIndex_objectlist.append(i);
      }
    }
    return SupportIndex_objectlist;
}

bool isStable(int index, vector<Object> objectlist) {
    vector<int> SupportIndex_objectlist = searchSupportObject(index, objectlist);
    if (searchSupportObject.size() == 1) return false;
    else {
      for (int j = 1; j < SupportIndex_objectlist.size(); j++) {
        if (stable_relation(objectlist[index], objectlist[SupportIndex_objectlist[j]])) {
          return true;
        }
      }
      return false;
    }
}

bool judge(const Object o1, const Object o2) {
  //假设横向为x方向，纵向为y方向
  if (o1.centerY != o2.centerY) return o1.centerY < o2.centerY;
  else return o1.centerX < o2.centerX;
}

void Local_stability(vector<Object>& objectlist) {
  sort(objectlist.begin(), objectlist.end(), judge);
  for (int i = 0; i < objectlist.size(); i++) {
    if (!isStable(index, objectlist)) {
      //估计支持区域
    }
  }
}
