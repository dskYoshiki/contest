import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
     
class Main
{
    static int solve(int d, ArrayList<Island> P)
    {
        Collections.sort(P);
     
        int answer = 1;
        double x = P.get(0).x;
        double y = P.get(0).y;
     
        for (Island p: P) {
            if (x + Math.sqrt(d*d - y*y) >= (p.x - Math.sqrt(d*d - p.y*p.y))) {
                if (x + Math.sqrt(d*d - y*y) > (p.x + Math.sqrt(d*d - p.y*p.y))) {
                    x = p.x;
                    y = p.y;
                }
            }
            else {
                answer++;
                x = p.x;
                y = p.y;
            }
        }
     
        return answer;
    }
     
    public static void main(String args[]) throws Exception
    {
        int n, d;
        int count = 0;
        int answer = 0;
     
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     
        String buffer = br.readLine();
        String[] temp = buffer.split(" ");
        n = Integer.parseInt(temp[0]);
        d = Integer.parseInt(temp[1]);
     
        while(n != 0 && d != 0) {
            count++;
     
            ArrayList<Island> P = new ArrayList<Island>();
            int x, y;
            for (int i = 0; i < n; i++) {
                buffer = br.readLine();
                temp = buffer.split(" ");
                x = Integer.parseInt(temp[0]);
                y = Integer.parseInt(temp[1]);
     
                P.add(new Island(x, y));
     
                if(y > d) {
                    answer = -1;
                }
            }
     
            if (answer != -1) {
                answer = solve(d, P);
            }
     
            System.out.println("Case " + count + ": " + answer);
     
            answer = 0;
            buffer = br.readLine();
            buffer = br.readLine();
            temp = buffer.split(" ");
            n = Integer.parseInt(temp[0]);
            d = Integer.parseInt(temp[1]);
        }
    }
}
     
class Island implements Comparable<Island> {
    int x, y;
     
    Island(int x, int y) {
        this.x = x;
        this.y = y;
    }
     
    public int compareTo(Island i) {
        return this.x - i.x;
    }
}

