#include "AI.hpp"

using namespace std;

struct Node{
    Position position;
    int distance;
    bool operator>(const Node& a) const{
        return this->distance > a.distance;
    }
};

vector<Angle> AI::calculatePath(Map * map, Position start, Position end){
    //Declare node

    priority_queue<Node, vector<Node>, greater<Node>> queue;

    //Add start node
    Node startNode = {start, 0};
    queue.push(startNode);

    //Declare visited
    vector<vector<int>> visited(map->getHeight(), vector<int>(map->getWidth(), -1));

    //Declare current node
    Node currentNode;

    Entity e = Entity();
    e.importMap(map);

    while (!queue.empty()){
        currentNode = queue.top();
        queue.pop();
        //TextScreen t("Current node:\n" + to_string(currentNode.position.getX()) + " " + to_string(currentNode.position.getY()) + "\n" + to_string(currentNode.distance) + "\nTarget:\n" + to_string(end.getX()) + " " + to_string(end.getY()) + "\n");
        //t.show();

        if (currentNode.position == end){
            break;
        }

        //Check if visited
        if (visited[currentNode.position.getY()][currentNode.position.getX()] != -1){
            continue;
        }

        //Mark as visited
        visited[currentNode.position.getY()][currentNode.position.getX()] = currentNode.distance;

        //Add neighbours
        for (int i = 0; i < 4; i++){
            Position nextPosition = currentNode.position;
            nextPosition.move(Angle(i), 1);
            e.teleportCheck(nextPosition);
            //Check if wall
            if (map->wall(nextPosition)){
                continue;
            }
            //Check if visited
            if (visited[nextPosition.getY()][nextPosition.getX()] != -1){
                continue;
            }
            //Add to queue
            Node nextNode = {nextPosition, currentNode.distance + 1};
            queue.push(nextNode);
        }
    }

    //Check if end was found
    if (currentNode.position != end){
        return vector<Angle>();
    }

    //TextScreen t("Path found\n \n");
    //t.show();

    //Declare path
    vector<Angle> path;

    //Add path
    while (currentNode.position != start){
        //Find lowest distance
        int lowestDistance = INT_MAX;
        Position lowestPosition;
        for (int i = 0; i < 4; i++){
            Position nextPosition = currentNode.position;
            nextPosition.move(Angle(i), 1);
            e.teleportCheck(nextPosition);
            if (visited[nextPosition.getY()][nextPosition.getX()] != -1 && visited[nextPosition.getY()][nextPosition.getX()] < lowestDistance){
                lowestDistance = visited[nextPosition.getY()][nextPosition.getX()];
                lowestPosition = nextPosition;
            }
        }

        Angle angle;
        if (lowestPosition.getX() == currentNode.position.getX()){
            if (lowestPosition.getY() > currentNode.position.getY()){
                angle = Angle(0);
            }else{
                angle = Angle(2);
            }
        }else{
            if (lowestPosition.getX() > currentNode.position.getX()){¨
                angle = Angle(3);
            }else{
                angle = Angle(1);
            }
        }
        if (lowestPosition.distance(currentNode.position) > 1){
            angle += 2;
        }
        path.push_back(angle);
        currentNode.position = lowestPosition;
    }

    //Reverse path
    reverse(path.begin(), path.end());

    string printPath = "";
    for (int i = 0; i < path.size(); i++){
        printPath += to_string(path[i].getAngle()) + " ";
    }
    //TextScreen t("Path calculated:\n" + printPath + "\n");
    //t.show();

    //cout << printPath << endl;

    return path;
}