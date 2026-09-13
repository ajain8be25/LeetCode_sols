class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        // Store the positions of 1s in img1
        vector<pair<int, int>> v1;

        // Store the positions of 1s in img2
        vector<pair<int, int>> v2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1) {
                    v1.push_back(make_pair(i, j));
                }

                if (img2[i][j] == 1) {
                    v2.push_back(make_pair(i, j));
                }
            }
        }

        int ans = 0;

        // Take one 1 from img1
        for (int i = 0; i < v1.size(); i++) {

            // Match it with every 1 from img2
            for (int j = 0; j < v2.size(); j++) {

                // Find the shift required to make
                // v1[i] overlap with v2[j]

                int rowShift = v2[j].first - v1[i].first;
                int colShift = v2[j].second - v1[i].second;

                int overlap = 0;

                // Apply this same shift to every 1 in img1
                for (int k = 0; k < v1.size(); k++) {

                    int newRow = v1[k].first + rowShift;
                    int newCol = v1[k].second + colShift;

                    // Check if the new position is inside the image
                    if (newRow >= 0 && newRow < n &&
                        newCol >= 0 && newCol < n) {

                        // Check if img2 also has a 1 there
                        if (img2[newRow][newCol] == 1) {
                            overlap++;
                        }
                    }
                }

                // Keep the maximum overlap
                if (overlap > ans) {
                    ans = overlap;
                }
            }
        }

        return ans;
    }
};