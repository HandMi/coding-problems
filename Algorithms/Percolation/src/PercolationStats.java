import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.Stopwatch;

public class PercolationStats
{
    private double[] results;
    private int trials;

    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials)
    {
        this.trials = trials;
        if (trials < 1)
            throw new IllegalArgumentException("n smaller than 1");
        if (trials < 1)
            throw new IllegalArgumentException(
                "number of trials smaller than 1");
        results = new double[trials];

        for (int i = 0; i < trials; ++i)
        {
            Percolation perc = new Percolation(n);
            while (!perc.percolates())
            {
                int row = StdRandom.uniform(1, n + 1);
                int col = StdRandom.uniform(1, n + 1);
                perc.open(row, col);
            }
            int open = perc.numberOfOpenSites();
            results[i] = (double)open / (n * n);
        }
    }

    // sample mean of percolation threshold
    public double mean() { return StdStats.mean(results); }

    // sample standard deviation of percolation threshold
    public double stddev() { return StdStats.stddev(results); }

    // low endpoint of 95% confidence interval
    public double confidenceLo()
    {
        return mean() - 1.96 * stddev() / Math.sqrt(trials);
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi()
    {
        return mean() + ((1.96 * stddev()) / Math.sqrt(trials));
    }

    // test client (see below)
    public static void main(String[] args)
    {
        if (args.length < 2)
        {
            throw new IllegalArgumentException(
                "pass two arguments n and trials");
        }
        int n = Integer.parseInt(args[0]);
        int trials = Integer.parseInt(args[1]);
        Stopwatch stopwatch = new Stopwatch();
        PercolationStats percolationStats = new PercolationStats(n, trials);
        double time = stopwatch.elapsedTime();

        StdOut.println("mean = " + percolationStats.mean());
        StdOut.println("stddev = " + percolationStats.stddev());
        StdOut.println("95% confidence interval = [" +
                       percolationStats.confidenceLo() + ", " +
                       percolationStats.confidenceHi() + "]");
        StdOut.println("elapsed time = " + time);
    }
}
