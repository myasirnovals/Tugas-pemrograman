import React from 'react';
import {
  Container,
  Box,
  Grid,
  Typography,
  Button,
  Card,
  CardContent,
  CardActions,
  IconButton,
} from '@mui/material';
import AddIcon from '@mui/icons-material/Add';
import EditIcon from '@mui/icons-material/Edit';
import DeleteIcon from '@mui/icons-material/Delete';

const addresses = [
  {
    id: 1,
    name: 'John Doe',
    phone: '08123456789',
    address: 'Jl. Mawar No. 1, Jakarta',
  },
  {
    id: 2,
    name: 'Jane Smith',
    phone: '08198765432',
    address: 'Jl. Melati No. 2, Bandung',
  },
];

const AlamatPage = () => {
  const handleAddAddress = () => {
    // Logic untuk menambahkan alamat baru
  };

  const handleEditAddress = (id) => {
    // Logic untuk mengedit alamat
  };

  const handleDeleteAddress = (id) => {
    // Logic untuk menghapus alamat
  };

  return (
    <Container>
      <Box mt={4} mb={2}>
        <Typography variant="h4" component="h1" gutterBottom>
          Daftar Alamat
        </Typography>
      </Box>
      <Grid container spacing={3}>
        {addresses.map((address) => (
          <Grid item xs={12} sm={6} md={4} key={address.id}>
            <Card>
              <CardContent>
                <Typography variant="h6">{address.name}</Typography>
                <Typography color="textSecondary">{address.phone}</Typography>
                <Typography color="textSecondary">{address.address}</Typography>
              </CardContent>
              <CardActions>
                <IconButton onClick={() => handleEditAddress(address.id)}>
                  <EditIcon />
                </IconButton>
                <IconButton onClick={() => handleDeleteAddress(address.id)}>
                  <DeleteIcon />
                </IconButton>
              </CardActions>
            </Card>
          </Grid>
        ))}
        <Grid item xs={12} sm={6} md={4}>
          <Button
            variant="contained"
            color="primary"
            startIcon={<AddIcon />}
            onClick={handleAddAddress}
            fullWidth
            style={{ height: '100%' }}
          >
            Tambah Alamat Baru
          </Button>
        </Grid>
      </Grid>
    </Container>
  );
};

export default AlamatPage;
