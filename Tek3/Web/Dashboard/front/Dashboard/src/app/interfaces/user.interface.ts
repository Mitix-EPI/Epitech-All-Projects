export interface User {
  id: string;
  email: string;
  password?: string;
  idOAuth2?: string;
  service?: 'Google' | 'Facebook' | 'Microsoft' | 'None';
  urlCover: string;
  spotifyAuthToken?: string;
};
