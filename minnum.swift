import UIKit
var minNumberInArray = 100
let testArray: [Int] = [6,2,9,2,13,85,1,-12,168]
for index in testArray {
    if index < minNumberInArray {
        minNumberInArray = index
    }
}
print(minNumberInArray)
