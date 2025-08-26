class Solution:
    def areaOfMaxDiagonal(self, dim: List[List[int]]) -> int:
        n=len(dim)
        area=-1
        dig=-1
        for it in dim:
            l=it[0]
            r=it[1]
            d=sqrt(l*l+r*r)
            if d>dig:
                area=l*r
                dig=d
            elif d==dig:
                area=max(area,l*r)


        return area
        