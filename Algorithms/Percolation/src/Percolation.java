import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation
{

    private boolean[][] grid;
    private int n;
    private int openSites;
    private int top;
    private int bottom;
    private WeightedQuickUnionUF grid_percolation;
    private WeightedQuickUnionUF grid_full;

    // is the site (row, col) full?
    private boolean validate(int row, int col)
    {
        if (row <= 0 || row > n)
            throw new IndexOutOfBoundsException("Row " + row +
                                                " out of bounds");
        if (col <= 0 || col > n)
            throw new IndexOutOfBoundsException("Col " + col +
                                                " out of bounds");
        return true;
    }
    private int xyTo1D(int row, int col) { return row * (n + 2) + col; }

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
        grid_percolation = new WeightedQuickUnionUF(bottom + 1);
        grid_full = new WeightedQuickUnionUF(bottom + 1);
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col)
    {
        validate(row, col);
        grid[row][col] = true;
        ++openSites;
        int[][] directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        if (row == 1)
        {
            grid_percolation.union(xyTo1D(row, col), top);
            grid_full.union(xyTo1D(row, col), top);
        }
        if (row == n)
            grid_percolation.union(xyTo1D(row, col), bottom);
        for (int[] d : directions)
        {
            if (grid[row + d[0]][col + d[1]])
            {
                grid_percolation.union(xyTo1D(row, col),
                                       xyTo1D(row + d[0], col + d[1]));
                grid_full.union(xyTo1D(row, col),
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
        return grid_full.connected(xyTo1D(row, col), top);
    }

    // returns the number of open sites
    public int numberOfOpenSites() { return openSites; }

    // does the system percolate?
    public boolean percolates()
    {
        return grid_percolation.connected(top, bottom);
    }
}
