import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation
{

    private boolean[][] grid;
    private int n;
    private int openSites;
    private int top;
    private int bottom;
    private WeightedQuickUnionUF gridPercolation;
    private WeightedQuickUnionUF gridFull;

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n)
    {
        if (n <= 0)
            throw new IllegalArgumentException("n must be larger than 0");
        this.n = n;
        openSites = 0;
        grid = new boolean[n + 2][n + 2];
        top = 0;
        bottom = (n + 2) * (n + 2);
        gridPercolation = new WeightedQuickUnionUF(bottom + 1);
        gridFull = new WeightedQuickUnionUF(bottom + 1);
    }

    // is the site (row, col) full?
    private void validate(int row, int col)
    {
        if (row <= 0 || row > n)
            throw new IllegalArgumentException("Row " + row + " out of bounds");
        if (col <= 0 || col > n)
            throw new IllegalArgumentException("Col " + col + " out of bounds");
    }

    private int xyTo1D(int row, int col) { return row * (n + 2) + col; }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col)
    {
        validate(row, col);
        if (grid[row][col])
        {
            return;
        }
        grid[row][col] = true;
        ++openSites;
        int[][] directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        if (row == 1)
        {
            gridPercolation.union(xyTo1D(row, col), top);
            gridFull.union(xyTo1D(row, col), top);
        }
        if (row == n)
            gridPercolation.union(xyTo1D(row, col), bottom);
        for (int[] d : directions)
        {
            if (grid[row + d[0]][col + d[1]])
            {
                gridPercolation.union(xyTo1D(row, col),
                                      xyTo1D(row + d[0], col + d[1]));
                gridFull.union(xyTo1D(row, col),
                               xyTo1D(row + d[0], col + d[1]));
            }
        }
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col)
    {
        validate(row, col);
        return grid[row][col];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col)
    {
        validate(row, col);
        return gridFull.find(xyTo1D(row, col)) == gridFull.find(top);
    }

    // returns the number of open sites
    public int numberOfOpenSites() { return openSites; }

    // does the system percolate?
    public boolean percolates()
    {
        if (n == 1)
            return isOpen(1, 1);
        return gridPercolation.find(top) == gridPercolation.find(bottom);
    }
}
