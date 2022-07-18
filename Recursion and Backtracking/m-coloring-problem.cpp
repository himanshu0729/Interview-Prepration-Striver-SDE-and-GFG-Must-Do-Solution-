bool isValid(int ver, int col,  bool graph[101][101], vector<int> &colorAssign){
    for(int i = 0; i < colorAssign.size(); i++){
        if(graph[ver][i] && colorAssign[i] == col)
            return false;
    }
    return true;
}
bool giveColor(int ver, bool graph[101][101], int n, int c, vector<int> &colorAssign){
    
    if(ver == n)
    {
        return true;
    }
    for(int col = 1; col <= c; col++){
        if(isValid(ver, col, graph, colorAssign)){
            colorAssign[ver] = col;
            if(giveColor(ver+1, graph, n, c, colorAssign))
                return true;
            colorAssign[ver] = -1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> colorAssign(n, -1);
    return giveColor(0,graph, n, m,colorAssign);
}
