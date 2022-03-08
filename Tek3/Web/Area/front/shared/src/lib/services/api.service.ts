import { Injectable } from "@angular/core";
import { CookieService } from "ngx-cookie-service";
import { HttpClient, HttpHeaders } from "@angular/common/http";
import { Observable } from "rxjs";

@Injectable({
  providedIn: "root",
})
export class ApiService {
  private REST_API_SERVER = "http://localhost:8080";

  private authToken = "";

  constructor(
    private httpClient: HttpClient,
    private cookieService: CookieService
  ) {
    this.authToken = this.cookieService.get("area_session");
  }

  setServer(serverIp: string) {
    this.REST_API_SERVER = serverIp;
    console.log("ServerIp set !", serverIp);
  }


  public sendGetRequest(endpoint: string, args: any = {}): Observable<any> {
    this.authToken = this.cookieService.get("area_session");
    let argsStr = "";
    if (args) {
      for (const k in args) {
        if (k) {
          argsStr += (argsStr === "" ? "?" : "&") + k + "=" + args[k];
        }
      }
    }
    return this.httpClient.get(
      this.REST_API_SERVER + "/" + endpoint + argsStr,
      {
        headers: new HttpHeaders().set(
          "x-token",
          `Bearer ${this.authToken}`
        ).append("Access-Control-Allow-Origin", "*")
      }
    );
  }

  public sendPostRequest(endpoint: string, args: any = {}, headers?: any): Observable<any> {
    this.authToken = this.cookieService.get("area_session");
    return this.httpClient.post(this.REST_API_SERVER + "/" + endpoint, args, {
      headers: new HttpHeaders().set(
        "x-token",
        `Bearer ${this.authToken}`
      ),
    });
  }

  public sendPutRequest(endpoint: string, args: any = {}): Observable<any> {
    this.authToken = this.cookieService.get("area_session");
    return this.httpClient.put(this.REST_API_SERVER + "/" + endpoint, args, {
      headers: new HttpHeaders().set(
        "x-token",
        `Bearer ${this.authToken}`
      ),
    });
  }

  public sendPatchRequest(endpoint: string, args: any = {}): Observable<any> {
    this.authToken = this.cookieService.get("area_session");
    return this.httpClient.patch(this.REST_API_SERVER + "/" + endpoint, args, {
      headers: new HttpHeaders().set(
        "x-token",
        `Bearer ${this.authToken}`
      ),
    });
  }

  saveToken(token: string): void {
    this.cookieService.set("area_session", token);
    this.authToken = token;
  }

  getToken(): string {
    return this.authToken;
  }

  logout(): void {
    this.cookieService.delete("area_session");
    window.location.href = "/";
  }
}
