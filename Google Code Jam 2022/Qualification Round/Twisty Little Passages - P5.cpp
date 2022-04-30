#include <iostream>
#include <unordered_map>

unsigned long computeMax(unsigned long N, unsigned long edges) {
    return (N * (N-1) / 2) + edges;
}

unsigned long computeMin(unsigned long N, unsigned long edges) {
    return (N / 2) + edges;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int test_case = 0; test_case < T; test_case++) {
        int responseCode;
        unsigned long N;
        unsigned long K;
        unsigned long prevMax;
        unsigned long prevMin;
        unsigned long currMax;
        unsigned long currMin;
        unsigned long totalEdges = 0;
        unsigned long totalVisited = 0;
        unsigned long nextToTeleportTo = N;
        bool isEven;
        bool walked;
        std::unordered_map<unsigned int, bool> visited;
        std::unordered_map<unsigned int, bool> walkedFrom;
        std::cin >> N >> K;
        unsigned int current_room;
        unsigned long passages;
        std::cin >> current_room >> passages;
        if (N == 1) {
            std::cout << "E 0" << "\n" << std::flush;
            std::cin >> responseCode;
        } else if(N == 2) {
            std::cout << "E 1" << "\n" << std::flush;
            std::cin >> responseCode;
        } else {
            visited[current_room] = true;
            totalVisited++;
            prevMax = computeMax(N, 0);
            prevMin = computeMin(N, 0);
            totalEdges += passages;
            currMax = computeMax(N-totalVisited, totalEdges);
            currMin = computeMin(N-totalVisited, totalEdges);
            
            unsigned long maxMinBound = currMin * 4 / 3;
            unsigned long minMaxBound = currMax * 2 / 3;
            
            // everything should be computed at the start
            for (int i = 0; i < K; i++) {
                if (maxMinBound >= minMaxBound) {
                    break;
                }
                // make a decision
                if (prevMax - currMax >= currMin - prevMin) {
                    // Teleport - where?
                    if (nextToTeleportTo <= 0) {
                        // Teleport to N / 2
                        std::cout << "T " << N / 2 << "\n" << std::flush;
                        std::cin >> responseCode;
                    } else {
                        // Teleport to nextToTeleportTo
                        std::cout << "T " << nextToTeleportTo << "\n" << std::flush;
                        std::cin >> responseCode;
                        nextToTeleportTo--;
                    }
                    walked = false;
                } else {
                    // Walk
                    if(walkedFrom[current_room]) {
                        // actually teleport to 1
                        std::cout << "T " << 1 << "\n" << std::flush;
                        std::cin >> responseCode;
                        walked = false;
                    } else {
                        std::cout << "W" << "\n" << std::flush;
                        std::cin >> responseCode;
                        walked = true;
                        walkedFrom[current_room] = true;
                    }
                }
                // do state calculations
                std::cin >> current_room >> passages;
                if (walked) {
                    if(visited[current_room]) {
                        totalEdges--;
                    } else {
                        totalEdges = totalEdges - 1 + passages;
                        visited[current_room] = true;
                    }
                } else {
                    // we have teleported
                    if(!visited[current_room]) {
                        totalEdges += passages;
                        visited[current_room] = true;
                    }
                }
                
                // update calculations
                prevMax = currMax;
                prevMin = currMin;
                currMax = computeMax(N-totalVisited, totalEdges);
                currMin = computeMin(N-totalVisited, totalEdges);
                maxMinBound = currMin * 4 / 3;
                minMaxBound = currMax * 2 / 3;
            }
            std::cout << "E " << ((maxMinBound - minMaxBound) / 2) << "\n" << std::flush;
            std::cin >> responseCode;
            if (responseCode == -1) { break; }
        }
    }
}