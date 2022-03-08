export interface ServiceWidget {
  id: number;
  color: string;
  icon: string;
  service: 'Youtube' | 'Github' | 'NASA' | 'Spotify' | 'Weather' | 'CurrencyConverter' | 'None';
  title: string;
  city: string;
  date: string;
  urlProfile: string;
  coords: { x: number, y: number };
};
